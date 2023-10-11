CREATE FUNCTION GetLastRegister(
	@TableName varchar(50)
)
RETURNS int
AS
BEGIN
	DECLARE @Id int 
	DECLARE @COLUMN int 
	DECLARE @Table varchar(50) = @TableName
	DECLARE @q varchar(1000)

	SELECT TOP 1 @COLUMN = COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS
				WHERE TABLE_NAME = @TableName
				ORDER BY ORDINAL_POSITION

	SET @q = 'SELECT' + @Id + '=' + @COLUMN + 'FROM' + @TableName +'WHERE' +@COLUMN + '=' + 'SCOPE_INDETITY()'

	exec(@q)

	RETURN @Id

END