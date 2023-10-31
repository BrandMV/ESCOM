USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spDeleteMedicine]
@Id int
AS
BEGIN
	
		DELETE FROM Medicamento WHERE idMedicamento = @Id
		SELECT 200 'StatusCode', 'El medicamento se elimino correctamente' 'Message'
	
END