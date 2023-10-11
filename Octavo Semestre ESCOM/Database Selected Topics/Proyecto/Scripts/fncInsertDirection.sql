CREATE FUNCTION InsertDirection()
RETURNS int
AS
BEGIN
	DECLARE @Id int 
	
		-- Obtenemos el �ltimo registro de la direcci�n que corresponde a la direcci�n del paciente que queremos
		--insertar
		SELECT @Id = idDireccion FROM Direccion WHERE idDireccion = SCOPE_IDENTITY();

	RETURN @Id

END