CREATE FUNCTION IsMedicineRegistered(
	@NombreComun varchar(50),
	@IdMedicina int
)
RETURNS int
AS
BEGIN
	DECLARE @existe int 
	
	SELECT @existe = COUNT(*)
	FROM Medicamento
	WHERE nombreComun = @NombreComun AND idMedicamento <> @IdMedicina

	RETURN @existe

END