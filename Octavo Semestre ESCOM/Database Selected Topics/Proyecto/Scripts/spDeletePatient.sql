USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spDeletePatient]
@Id int
AS
BEGIN
	
		DELETE FROM Paciente WHERE idPaciente = @Id
		SELECT 200 'StatusCode', 'El paciente se elimino correctamente' 'Message'
	
END