USE [Hospital]
GO
/****** Object:  StoredProcedure [dbo].[spGetAppointmentsByPatient]    Script Date: 30/05/2023 08:33:07 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spGetProviderById]
@Id int
AS
BEGIN
	SELECT * FROM [dbo].[Fabricante] WHERE idFabricante = @Id;
END
