CREATE PROCEDURE spDeleteAppointment
@IdCita int,
@IdPaciente int
AS
BEGIN
	DECLARE @FechaActual DATETIME = GETDATE();
	DECLARE @Cita int = (SELECT COUNT(*) FROM Cita WHERE DATEDIFF(HOUR, GETDATE(), Fecha) > 24 AND idCita = @IdCita)

	IF @CIta > 0 
	BEGIN
		DELETE FROM Cita WHERE idCita = @IdCita
	END
	ELSE
	BEGIN
		 SELECT 500 'StatusCode', 'No puedes cancelar tu cita si faltan menos de 24 horas' 'Message'
	END
	
END

