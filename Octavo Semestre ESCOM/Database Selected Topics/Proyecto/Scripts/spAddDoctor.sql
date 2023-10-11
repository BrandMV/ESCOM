USE [Hospital]
GO
/****** Object:  StoredProcedure [dbo].[spAddDoctor]    Script Date: 26/05/2023 09:35:52 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[spAddDoctor]
@RFC varchar(13),
@Nombre varchar(50),
@SegundoNombre varchar(50),
@Paterno varchar(50),
@Materno varchar(50),
@Salario money,
@Telefono varchar(20),
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

	--SELECT @existe = COUNT(*)
	--FROM Personal
	--WHERE RFC = @RFC OR email = @Email

	SET @existe = dbo.IsPersonalRegistered(@RFC, @Email)

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El doctor ya existe' 'Message'
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
		INSERT INTO Personal(RFC, nombre, segundoNombre, paterno, materno, salario, telefono, email, idDireccion, fechaNacimiento)
		VALUES(@RFC, @Nombre, @SegundoNombre, @Paterno, @Materno, @Salario, @Telefono, @Email, dbo.InsertDirection(), @FechaNacimiento)
		--Insertando en la tabla medico
	   INSERT INTO Medico(cedulaProfesional, password, idConsultorio, RFC)
	   VALUES (@Cedula, @Contrasena, @IdConsultorio, @RFC);

	   SELECT 200 'StatusCode', 'El medico se agrego correctamente' 'Message'
	END
	

END