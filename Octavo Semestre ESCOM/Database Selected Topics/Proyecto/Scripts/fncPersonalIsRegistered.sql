CREATE FUNCTION IsPersonalRegistered(
	@RFC varchar(13),
	@Email varchar(256)
)
RETURNS int
AS
BEGIN
	DECLARE @existe int 
	
	SELECT @existe = COUNT(*)
	FROM Personal
	WHERE RFC = @RFC OR email = @Email

	RETURN @existe

END