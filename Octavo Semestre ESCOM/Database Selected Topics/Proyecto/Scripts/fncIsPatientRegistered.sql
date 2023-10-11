USE [Hospital]
GO
/****** Object:  UserDefinedFunction [dbo].[IsPatientRegistered]    Script Date: 26/05/2023 07:53:08 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER FUNCTION [dbo].[IsPatientRegistered](
	@Email varchar(256),
	@Id int
)
RETURNS int
AS
BEGIN
	DECLARE @existe int 
	
	SELECT @existe = COUNT(*)
	FROM Paciente
	WHERE email = @Email AND idPaciente <> @Id

	RETURN @existe

END