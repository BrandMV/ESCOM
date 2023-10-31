USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spAddMedicine]
@IdFabricante int,
@NombreComun varchar(50),
@Docificacion varchar(50),
@Formula varchar(50),
@Precio money,
@Precauciones varchar(200)
AS
BEGIN
	DECLARE @existe INT;

	SELECT @existe = COUNT(*)
	FROM Medicamento
	WHERE nombreComun = @NombreComun

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El medicamento ya existe' 'Message'
	END
	ELSE
	BEGIN

	   INSERT INTO Medicamento(nombreComun, formaFarmaceutica, precio, dosificacionRecomendada, precauciones, idFabricante)
	   VALUES (@NombreComun, @Formula, @Precio, @Docificacion, @Precauciones, @IdFabricante);

	   SELECT 200 'StatusCode', 'La medicina se agrego correctamente' 'Message'
	END

END