CREATE PROCEDURE spGetAvailableHours
@Fecha DATE,
@RFC varchar(13),
@IdMedico int
AS
BEGIN

	DECLARE @HoraEntrada VARCHAR(8) = (SELECT TOP 1 CONVERT(VARCHAR(8), entrada, 108) FROM Horario WHERE RFC = @RFC)
	--SELECT @HoraEntrada
	DECLARE @HoraSalida VARCHAR(8) = (SELECT TOP 1 CONVERT(VARCHAR(8), salida, 108) FROM Horario WHERE RFC = @RFC)
	-- SELECT @HoraSalida
	CREATE TABLE #HorasIntermedias (Hora varchar(8));

	-- Generar las horas intermedias utilizando una tabla de números
	DECLARE @HoraActual TIME = @HoraEntrada;

	WHILE @HoraActual <= @HoraSalida
	BEGIN
		INSERT INTO #HorasIntermedias (Hora)
		VALUES (@HoraActual);
    
		SET @HoraActual = DATEADD(HOUR, 1, @HoraActual);
	END

	CREATE TABLE #HorasDisponibles (Hora TiME)
	DECLARE @CitasEnFecha int = (SELECT COUNT(*)FROM Cita
									WHERE CONVERT(date, Fecha) = CONVERT(date, @Fecha) 
									AND idMedico = @IdMedico)

	SELECT * FROM #HorasIntermedias WHERE Hora NOT IN((SELECT CONVERT(VARCHAR(8), Fecha, 108) FROM Cita WHERE CONVERT(date, Fecha) = CONVERT(date, @Fecha) 
									AND idMedico = @IdMedico))
	DROP TABLE #HorasIntermedias
	DROP TABLE #HorasDisponibles
END


