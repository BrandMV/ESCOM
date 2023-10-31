USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].spUpdatePatient
@Id int,
@IdDireccion int,
@Nombre varchar(50),
@Paterno varchar(50),
@Materno varchar(50),
@FechaNacimiento datetime,
@Email varchar(256),
@Contrasena varchar(20),
@Telefono varchar(20),
@Estado varchar(30),
@Colonia varchar(30),
@Municipio varchar(30),
@Calle varchar(30),
@NoExterior int,
@NoInterior int,
@Cp varchar(5)
AS
BEGIN
	DECLARE @existe INT;

	--SELECT @existe = COUNT(*)
	--FROM Paciente
	--WHERE email = @Email OR username = @UserName AND idPaciente <> @Id

	SET @existe = dbo.IsPatientRegistered(@Email, @Id)

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'Ya existe un paciente con este correo o nombre de usuario' 'Message'
	END
	ELSE
	BEGIN

	-- Actualizamos su dirección
	UPDATE Direccion
		SET noExterior = @NoExterior,
		noInterior = @NoInterior,
		estado = @Estado,
		municipio = @Municipio,
		colonia = @Colonia,
		calle = @Calle,
		cp = @Cp
		WHERE idDireccion = @IdDireccion

		--Actualizamos datos del paciente
		UPDATE Paciente
		SET nombre = @Nombre,
		paterno = @Paterno,
		materno = @Materno,
		fechaNacimiento = @FechaNacimiento,
		password = @Contrasena,
		email = @Email,
		telefono = @Telefono
		WHERE idPaciente = @Id

	   SELECT 200 'StatusCode', 'El paciente se actualizo correctamente' 'Message'
	END
END