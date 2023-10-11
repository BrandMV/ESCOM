USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spGetAppointmentsByPatient]
@IdPatient int
AS
BEGIN
	SELECT * FROM [dbo].[Cita] WHERE idPaciente = @IdPatient;
END
GO