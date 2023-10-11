CREATE FUNCTION InsertDirection()
RETURNS int
AS
BEGIN
	DECLARE @Id int 
	
		-- Obtenemos el último registro de la dirección que corresponde a la dirección del paciente que queremos
		--insertar
		SELECT @Id = idDireccion FROM Direccion WHERE idDireccion = SCOPE_IDENTITY();

	RETURN @Id

END