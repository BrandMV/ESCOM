USE [Hospital]
GO
/****** Object:  Trigger [dbo].[TR_INS_DEL_Paciente]    Script Date: 06/06/2023 05:35:43 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[TR_INS_DEL_Paciente]
ON [dbo].[Paciente]
AFTER INSERT, DELETE
AS BEGIN 
	IF EXISTS(SELECT * FROM inserted) AND NOT EXISTS(SELECT * FROM deleted)
    BEGIN
        -- Operación de inserción
		INSERT INTO Bitacora_Paciente(operacion, usuario, host,modificado, tabla, pacienteId)
		VALUES('INSERT',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted))
    END
	 -- Verificar si es una operación de eliminación
    IF NOT EXISTS(SELECT * FROM inserted) AND EXISTS(SELECT * FROM deleted)
    BEGIN
        -- Operación de eliminación
        INSERT INTO Bitacora_Paciente(operacion, usuario, host,modificado, tabla, pacienteId)
		VALUES('DELETE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM deleted))
    END
END 

