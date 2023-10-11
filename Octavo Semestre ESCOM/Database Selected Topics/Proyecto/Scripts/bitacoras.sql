USE Hospital

-- CREAMOS LA TABLA BITÁCORA donde guadaremos la información a auditar 
CREATE TABLE Bitacora_Medicamentos
(
ID INT IDENTITY NOT NULL, 
operacion VARCHAR(10) DEFAULT NULL, 
usuario VARCHAR(40) DEFAULT NULL,
host VARCHAR(30) DEFAULT NULL,
modificado DATETIME DEFAULT NULL, 
tabla VARCHAR(40) NOT NULL, 
PRIMARY KEY (ID)
)

-- DELETE FROM  Bitacora_persona

-- CREAMOS TRIGGER DE INSERT PARA LA TABLA Medicamentos 
ALTER TRIGGER TR_INS_Medicamento
ON Medicamento
AFTER INSERT
AS BEGIN 
	INSERT INTO Bitacora_Medicamentos(operacion, usuario, host,modificado, tabla)
	VALUES('INSERT',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Medicamento')
END 

ALTER TRIGGER TR_DEL_Medicamento
ON Medicamento
AFTER DELETE
AS BEGIN 
	INSERT INTO Bitacora_Medicamentos(operacion, usuario, host,modificado, tabla)
	VALUES('DELETE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Medicamento')
END 

CREATE TRIGGER TR_UPD_Medicamento
ON Medicamento
AFTER UPDATE
AS BEGIN 
	INSERT INTO Bitacora_Medicamentos(operacion, usuario, host,modificado, tabla)
	VALUES('UPDATE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Medicamento')
END 

-- CREAMOS LA TABLA BITÁCORA donde guadaremos la información a auditar 
CREATE TABLE Bitacora_Doctor
(
ID INT IDENTITY NOT NULL, 
operacion VARCHAR(10) DEFAULT NULL, 
usuario VARCHAR(40) DEFAULT NULL,
host VARCHAR(30) DEFAULT NULL,
modificado DATETIME DEFAULT NULL, 
tabla VARCHAR(40) NOT NULL, 
PRIMARY KEY (ID)
)


-- DELETE FROM  Bitacora_persona

-- CREAMOS TRIGGER DE INSERT PARA LA TABLA Medicamentos 
CREATE TRIGGER TR_INS_Medico
ON Medico
AFTER INSERT
AS BEGIN 
	INSERT INTO Bitacora_Doctor(operacion, usuario, host,modificado, tabla)
	VALUES('INSERT',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Medico')
END 

CREATE TRIGGER TR_DEL_Medico
ON Medico
AFTER DELETE
AS BEGIN 
	INSERT INTO Bitacora_Doctor(operacion, usuario, host,modificado, tabla)
	VALUES('DELETE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Medico')
END 

CREATE TABLE Bitacora_Paciente
(
ID INT IDENTITY NOT NULL, 
operacion VARCHAR(10) DEFAULT NULL, 
usuario VARCHAR(40) DEFAULT NULL,
host VARCHAR(30) DEFAULT NULL,
modificado DATETIME DEFAULT NULL, 
tabla VARCHAR(40) NOT NULL, 
PRIMARY KEY (ID)
)


-- DELETE FROM  Bitacora_persona

-- CREAMOS TRIGGER DE INSERT PARA LA TABLA Medicamentos 
CREATE TRIGGER TR_INS_Paciente
ON Paciente
AFTER INSERT
AS BEGIN 
	INSERT INTO Bitacora_Paciente(operacion, usuario, host,modificado, tabla)
	VALUES('INSERT',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente')
END 

CREATE TRIGGER TR_DEL_Paciente
ON Paciente
AFTER DELETE
AS BEGIN 
	INSERT INTO Bitacora_Paciente(operacion, usuario, host,modificado, tabla)
	VALUES('DELETE',SUSER_NAME(),@@SERVERNAME, GETDATE(),'Paciente')
END 

SELECT @@SERVERNAME