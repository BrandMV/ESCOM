package com.BrandMV.App.Constants;

public class Constants {

    //*Server configs
    public static final int PORT = 8000;
    //public static final int THREADS = 4;

    //*Server messages
    public static final String SERVER_CONNECTION_ERROR = "No se pudo iniciar el socket en el puerto %d";
    public static final String SERVER_CONNECTION_START = "Servidor iniciado, esperando clientes...";
    public static final String SERVER_CONNECTION_ACCEPTED = "Conexion aceptada...";
    public static final String SERVER_CONNECTION_STOPPED = "Servidor detenido";
    public static final String SERVER_CONNECTION_ACCEPTED_ERROR = "Error al aceptar una nueva conexion";
    public static final String SERVER_CONNECTION_STOPPED_ERROR = "Error al cerrar el socket del servidor";

    //*Utilities
    public static final int INPUT_STREAM_BYTES_SIZE = 65535;
    public static final String CONNECTED_CLIENT_MESSAGE = "\nCliente conectado desde: %s\nPor el puerto: %d";
    public static final String CONNECTED_CLIENT_DATA = "Datos: %s\r\n\r\n";

    public static final String HTTP_NOT_IMPLEMENTED = "HTTP/1.0 501 Not Implemented\r\n";

}
