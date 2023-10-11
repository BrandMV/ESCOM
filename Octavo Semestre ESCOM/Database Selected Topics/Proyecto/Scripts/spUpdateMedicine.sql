USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spUpdateMedicine]
@IdMedicina int,
@IdFabricante int,
@NombreComun varchar(50),
@Docificacion varchar(50),
@Formula varchar(50),
@Precio money,
@Precauciones varchar(200)
AS
BEGIN
	DECLARE @existe INT;

	--SELECT @existe = COUNT(*)
	--FROM Medicamento
	--WHERE nombreComun = @NombreComun AND idMedicamento <> @IdMedicina

	SET @existe = dbo.IsMedicineRegistered(@NombreComun, @IdMedicina)

	IF @existe > 0
	BEGIN
	   SELECT 500 'StatusCode', 'El medicamento ya existe' 'Message'
	END
	ELSE
	BEGIN
		UPDATE Medicamento
			SET nombreComun = @NombreComun,
			formaFarmaceutica = @Formula,
			precio = @Precio,
			dosificacionRecomendada = @Docificacion,
			precauciones = @Precauciones,
			idFabricante = @IdFabricante
			WHERE idMedicamento = @IdMedicina

	   SELECT 200 'StatusCode', 'La medicina se actualizo correctamente' 'Message'
	END

END