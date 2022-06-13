package constants;

/** The constants used during all the program*/
public class Constants {
    public static final int BUFFER_SIZE = 1024;

    /**Main*/
    public static final String SERVER_INIT_MSG = "Servidor iniciado";

    /**MULTICAST SERVER CONSTANTS*/
    public static final String MULTICAST_ADDRESS = "228.1.1.1";
    public static final int MULTICAST_PORT = 9015;

    /**RMI SERVER CONSTANTS*/
    public static final String FILES_PATH = "files";
    public static final int RMI_PORT = 1099;

    /**UNICAST SERVER CONSTANTS*/
    public static final int UNICAST_PORT = 9998;
    public static final String CLIENT_CONNECTION = "Cliente conectado desde: %s: desde el puerto: %d";
    public static final String SENDING_FILE = "Mandando el archivo";
    public static final String FILE_SIZE = "Archivo: %s con tamañao de %s";
    public static final String FILE_SENT_SUCCESSFULLY = "Archivo enviado exitosamente";
    public static final int FILE_BUFFER_SIZE = 1500;

}
