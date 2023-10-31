USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spUpdateAppointment]
@IdCita int,
@Descripcion varchar(100),
@Fecha datetime,
@IdMedico int,
@IdPaciente int
AS
BEGIN
	DECLARE @existe INT;

	SELECT @existe = COUNT(*)
	FROM Cita
	WHERE Fecha = @Fecha AND idMedico = @IdMedico AND idCita <> @IdCita

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El doctor ya tiene una cita para esa fecha' 'Message'
	END
	ELSE
	BEGIN
		UPDATE Cita
			SET descripcion = @Descripcion,
			 Fecha = @Fecha,
			 idMedico = @IdMedico,
			 idPaciente = @IdPaciente

		SELECT 200 'StatusCode', 'Cita actualizada correctamente' 'Message'
	END
END
GO