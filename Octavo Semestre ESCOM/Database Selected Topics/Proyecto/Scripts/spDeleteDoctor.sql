USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spDeleteDoctor]
@RFC varchar(13)
AS
BEGIN
	
		DELETE FROM Medico WHERE RFC = @RFC
		SELECT 200 'StatusCode', 'El medico se elimino correctamente' 'Message'
	
END