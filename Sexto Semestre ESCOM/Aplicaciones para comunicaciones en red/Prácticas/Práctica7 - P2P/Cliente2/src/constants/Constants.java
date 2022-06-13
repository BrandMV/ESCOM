package constants;

public class Constants {
    public static final int BUFFER_SIZE = 1024;

    /**App*/
    public static final String WINDOW_TITLE = "Práctica P2P";
    public static final String FILE_NAME_TEXT = "Nombre del archivo:";
    public static final String FILE_PATH_TEXT = "Ruta del archivo:";
    public static final String FILE_MD5_TEXT = "MD5 del archivo:";
    public static final String FILE_SERVER_TEXT = "Server del archivo:";
    public static final String DOWNLOAD_BTN_TEXT = "Descargar archivo";

    /**MULTICAST SERVER CONSTANTS*/
    public static final String MULTICAST_ADDRESS = "228.1.1.1";
    public static final int MULTICAST_PORT = 9014;

    /**RMI SERVER CONSTANTS*/
    public static final String FILES_PATH = "downloads/%s";
    public static final int RMI_PORT = 1099;

    /**UNICAST SERVER CONSTANTS*/
    public static final int UNICAST_PORT = 1234;
    public static final String FILE_RECEIVED_SUCCESSFULLY = "Archivo descargado exitosamente";
    public static final int FILE_BUFFER_SIZE = 1500;
    public static final String CLIENT_CONNECTED = "Cliente conectado";

    /**WARNINGS AND ERRORS MESSAGES*/
    public static final String EMPTY_SERVERS_MESSAGE = "No hay servidores";
}
