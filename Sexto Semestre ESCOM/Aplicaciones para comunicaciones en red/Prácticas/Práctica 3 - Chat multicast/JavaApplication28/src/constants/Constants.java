/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package constants;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author BrandMV
 * Class that contains all the constants used during the program
 */
public class Constants {
    
    //*Messages
    public static final String USER_CONNECTED = "Se ha conectado el usuario %s\n";
    public static final String USER_DISCONNECTED = "Se ha desconectado el usuario %s\n";
    public static final String CURRENT_USERS = "Usuarios conectados";
    public static final String USER_JOINED_FORMAT = "<inicio>%s";
    public static final String USER_DISCONNECTED_FORMAT = "<fin>%s";
    public static final String MESSAGE_FORMAT = "c<msg><%s>%s";
    public static final String PRIVATE_MESSAGE_FORMAT = "c<msg><privado><%s><%s>%s";
    public static final String USERNAME = "Ingresa un nombre de usuario para entrar al chat";
    public static final String WINDOW_TITLE = "Chat Multicast - %s";
    public static final String TEXT_AREA_MESSAGE = "%s\n%s: %s";
    
    //*Connection
    public static final String GROUP = "230.1.1.1"; 
    public static final int CLIENT_PTO = 9931;
    public static final int SERVER_PTO = 9930;
    public static final int BUFFER = 2048;
    
    //* Errors
    public static final String JOIN_GROUP_ERROR = "No fue posoble unirse al grupo";
    public static final String SERVER_ERROR = "No fue posoble conectarse al servidor";
    
    //*Emojis
    public static final Map<String,String> EMOJIS_LIST = Collections.unmodifiableMap(
            new HashMap<String,String>(){{
                put("😀", ":)");
                put("😄", ":D");
                put("😂", ":'D");
                put("😇", "0:>");
                put("😍", "<3)");
                put("😛", ":p");
                put("😎", "8)");
                put("😕", ":/");
                put("☹", ":(");
                put("😮", ":o");
                put("😢", ":'(");
                put("😠", ">:");
                put("💀", "X:");
                put("👽", "^0^");
                put("💋", ":kiss");
                put("💖", "<*3");
                put("💥", "**");
                put("🤘", "^|^");
                put("👉", "->");
                put("👍", "(Y)");
                
            }}
    );
    
    //* Audio
    
    public static final long RECORD_TIME = 5000;
    public static final String PATH_AUDIO_FORMAT = "Audios/%s - %s";
    public static final String AUDIO_NAME = "%s - %s.wav";
    
}
