USE [Hospital]
GO
/****** Object:  StoredProcedure [dbo].[spUserLogin]    Script Date: 15/06/2023 07:00:40 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spRecoverPassword]
@LoginCred varchar(100),
@Password varchar(100)
AS
BEGIN
	DECLARE @Passowrd varchar(100)
	IF EXISTS(SELECT 1 FROM Personal WHERE RFC = @LoginCred AND idUsuario = 2)
	BEGIN
		UPDATE Medico SET password = @Password
		WHERE RFC = @LoginCred
	END
	ELSE IF EXISTS(SELECT 1 FROM Personal WHERE RFC = @LoginCred AND idUsuario =  1)
	BEGIN 
		UPDATE Administrativo SET password = @Password
		WHERE RFC = @LoginCred
	END
	ELSE IF EXISTS(SELECT 1 FROM Paciente WHERE email = @LoginCred)
	BEGIN
		UPDATE Paciente SET password = @Password
		WHERE email = @LoginCred

	END
	ELSE
	BEGIN
		SELECT 500 'StatusCode', 'El usuario no existe' 'Message'
	END
		SELECT 200 'StatusCode', 'Contraseña recuperada' 'Message'

END

