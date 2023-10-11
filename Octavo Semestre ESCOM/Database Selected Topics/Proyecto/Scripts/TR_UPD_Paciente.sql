USE [Hospital]
GO
/****** Object:  Trigger [dbo].[TR_UPD_Paciente]    Script Date: 06/06/2023 05:36:18 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[TR_UPD_Paciente]
ON [dbo].[Paciente]
AFTER UPDATE
AS BEGIN 
	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.nombre <> d.nombre )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'nombre')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.paterno <> d.paterno )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'paterno')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.materno <> d.materno )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'materno')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.fechaNacimiento <> d.fechaNacimiento )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'fechaNacimiento')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.password <> d.password )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'password')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.email <> d.email )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'email')
    END

	IF EXISTS(SELECT * FROM inserted AS i JOIN deleted AS d ON i.idPaciente = d.idPaciente  
				WHERE i.telefono <> d.telefono )
    BEGIN
        INSERT INTO BitacoraUpdate_Paciente(operacion, usuario, host,modificado, tabla, pacienteId, campoModificado)
		VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente', (SELECT idPaciente FROM inserted), 'telefono')
    END

END 