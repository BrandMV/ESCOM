USE [Hospital]
GO
/****** Object:  StoredProcedure [dbo].[spGetAllDoctors]    Script Date: 13/06/2023 04:45:35 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spUserLogin]
@LoginCred varchar(100),
@Password varchar(100)
AS
BEGIN
	IF EXISTS(SELECT 1 FROM Medico WHERE RFC = @LoginCred AND password =  @Password)
	BEGIN
		SELECT p.RFC, nombre, segundoNombre, paterno, materno, salario, telefono, email, fechaNacimiento,
		m.cedulaProfesional, m.idConsultorio, u.tipo
		FROM Medico m INNER JOIN Personal p ON m.RFC = p.RFC 
		INNER JOIN Usuario u ON p.idUsuario = u.idUsuario
		WHERE m.RFC = @LoginCred AND password =  @Password
	END
	ELSE IF EXISTS(SELECT 1 FROM Administrativo WHERE RFC = @LoginCred AND password =  @Password)
	BEGIN 
		SELECT p.RFC, nombre, segundoNombre, paterno, materno, salario, telefono, email, fechaNacimiento,
		a.titulacion, u.tipo
		FROM Administrativo a INNER JOIN Personal p ON a.RFC = p.RFC 
		INNER JOIN Usuario u ON p.idUsuario = u.idUsuario
		WHERE a.RFC = @LoginCred AND password =  @Password
	END
	ELSE IF EXISTS(SELECT 1 FROM Paciente WHERE email = @LoginCred AND password =  @Password)
	BEGIN
		SELECT idPaciente, nombre, paterno, materno, fechaNacimiento, email, telefono, u.tipo
		FROM Paciente p INNER JOIN Usuario u ON p.idUsuario = u.idUsuario
		WHERE email = @LoginCred AND password = @Password
	END
	ELSE
	BEGIN
		SELECT 500 'StatusCode', 'Verifica tus datos' 'Message'
	END
END

execute dbo.spUserLogin 'prueba@prueba','123'
