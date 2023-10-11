USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spAddPatient]
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

	SELECT @existe = COUNT(*)
	FROM Paciente
	WHERE email = @Email

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El paciente ya existe' 'Message'
	END
	ELSE
	BEGIN
		Declare @IdDireccion int
		--Insertamos primero la dirección--
		INSERT INTO Direccion(noExterior, noInterior, estado, municipio, colonia, calle, cp)
		VALUES(@NoExterior, @NoExterior, @Estado, @Municipio, @Colonia, @Calle, @Cp)

		-- Obtenemos el último registro de la dirección que corresponde a la dirección del paciente que queremos
		--insertar

		--SELECT @IdDireccion = idDireccion FROM Direccion WHERE idDireccion = SCOPE_IDENTITY();

		SET @IdDireccion = dbo.InsertDirection()

	   INSERT INTO Paciente(nombre, paterno, materno, fechaNacimiento, password, email, telefono, idDireccion)
	   VALUES (@Nombre, @Paterno, @Materno, @FechaNacimiento, @Contrasena, @Email, @Telefono, @IdDireccion);

	   SELECT 200 'StatusCode', 'El paciente se agrego correctamente' 'Message'
	END

END