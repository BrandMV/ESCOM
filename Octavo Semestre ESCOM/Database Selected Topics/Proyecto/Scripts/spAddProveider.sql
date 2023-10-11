USE [Hospital]
GO
/****** Object:  StoredProcedure [dbo].[spAddDoctor]    Script Date: 18/06/2023 07:47:53 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[spAddProvider]
@infoRegistro varchar(50),
@infoLicencia varchar(50),
@telefono varchar(20),
@nombre varchar(50),
@sitioWeb varchar(50),
@email varchar(256),
@Estado varchar(30),
@Colonia varchar(30),
@Municipio varchar(30),
@Calle varchar(30),
@NoExterior int,
@NoInterior int,
@Cp varchar(5)
AS
BEGIN
	DECLARE @existe INT = ( SELECT COUNT(*) FROM Fabricante WHERE email = @email);


	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El fabricante ya existe' 'Message'
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

		--SET @IdDireccion = dbo.InsertDirection()
		
		-- Insertando datos en tabla personal
		INSERT INTO Fabricante(infoRegistro, infoLicencia, telefono, nombre, sitioWeb, email, idDireccion)
		VALUES(@infoRegistro, @infoLicencia, @telefono, @nombre, @sitioWeb, @email, dbo.InsertDirection())

	   SELECT 200 'StatusCode', 'El fabricante se agrego correctamente' 'Message'
	END
	

END