USE [Hospital]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spGetProviders]
AS
BEGIN
	SELECT idFabricante, nombre FROM [dbo].[Fabricante];
END
GO
