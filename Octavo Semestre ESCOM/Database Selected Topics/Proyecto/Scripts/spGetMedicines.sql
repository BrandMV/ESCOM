USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spGetMedicines]
AS
BEGIN
	SELECT * FROM [dbo].[Medicamento];
END
GO