USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spAddAppointment]
@Descripcion varchar(100),
@Fecha datetime,
@IdMedico int,
@IdPaciente int
AS
BEGIN
	DECLARE @existe INT;

	SELECT @existe = COUNT(*)
	FROM Cita
	WHERE Fecha = @Fecha AND idMedico = @IdMedico

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El doctor ya tiene una cita para esa fecha' 'Message'
	END
	ELSE
	BEGIN
		INSERT INTO Cita(descripcion, Fecha, idMedico, idPaciente)
		VALUES(@Descripcion, @Fecha, @IdMedico, @IdPaciente)

		SELECT 200 'StatusCode', 'Cita realizada correctamente' 'Message'
	END
END
GO