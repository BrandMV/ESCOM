USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spUpdateDoctor]
@Id int,
@RFC varchar(13),
@Nombre varchar(50),
@SegundoNombre varchar(50),
@Paterno varchar(50),
@Materno varchar(50),
@Salario money,
@Telefono varchar(20),
@IdDireccion int,
@Email varchar(256),
@Contrasena varchar(20),
@FechaNacimiento datetime,
@Estado varchar(30),
@Colonia varchar(30),
@Municipio varchar(30),
@Calle varchar(30),
@NoExterior int,
@NoInterior int,
@Cp varchar(5),
@IdConsultorio int,
@Cedula varchar(10)
AS
BEGIN
	DECLARE @existe INT;

	SELECT @existe = COUNT(*)
	FROM Medico
	WHERE RFC = @RFC AND idMedico <> @Id

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El doctor ya existe' 'Message'
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

		--Actualizamos datos del personal
		UPDATE Personal
		SET RFC = @RFC,
		nombre = @Nombre,
		segundoNombre = @SegundoNombre,
		paterno = @Paterno,
		materno = @Materno,
		salario = @Salario,
		email = @Email,
		telefono = @Telefono,
		fechaNacimiento = @FechaNacimiento
		WHERE RFC = @RFC

		--Actualizamos datos del doctor
		UPDATE Medico
			SET cedulaProfesional = @Cedula,
			password = @Contrasena,
			idConsultorio = @IdConsultorio,
			RFC = @RFC
			WHERE idMedico = @Id

	   SELECT 200 'StatusCode', 'El medico se actualizo correctamente' 'Message'
	END

END