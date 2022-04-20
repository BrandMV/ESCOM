/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import Connection.Connection;
import constants.Constants;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.SocketAddress;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author BrandonMV
 */
public class Server extends Thread{
    
    private ArrayList<String> users;
    private static MulticastSocket s;
    private static DatagramPacket packet;
    private ObjectInputStream ois;
    private ByteArrayInputStream bais;
    private byte[] buffer;
    private InetAddress group;
    private byte[] data;
    private String message;
    private NetworkInterface ni;
    private boolean request;
    
    public Server(){
        users = new ArrayList();
        group = null;
        message = "";
    }


    /**
     * Thread used to connect the server app
     * @param none
     * @return none
     */
    @Override
    public void run(){
        request = true; //* requesting server for the very first time
        for(;;){
            try{
                //* Joning to the multicast group
                group = InetAddress.getByName(Constants.GROUP);
                s = new MulticastSocket(Constants.SERVER_PTO);
                //* Connecting to the server
                serverConnect();
                 s.setTimeToLive(100); //* Server TTL
                buffer = new byte[Constants.BUFFER];
                packet = new DatagramPacket(buffer, buffer.length);
                //* Recieving message from client
                s.receive(packet);
                data = packet.getData();
                message = new String(data);
                
                System.out.println("Mensaje: " + message);
                
                //* Determining type of message
                if(message.contains("<inicio>")){
                    message = message.substring(8);   // User name being substract
                    String username = "";
                    String usersS;
                    //* Determining the user who just joined
                    for(int i = 0; Character.isLetter(message.charAt(i)) && i < message.length(); i++) username = username + message.charAt(i); // Concat the username into a new string
                    users.add(username);
                    usersS = "<usuarios>" + users.toString(); //* Converting the array of users into a string ready to be sent
                    System.out.println("Usuarios: " +  usersS);
                    //* Sending packet
                    sendPacket(usersS, group);
                }else if(message.contains("c<msg>")){
                    //* Extracting message from the client
                    message = message.substring(1);
                    message = "s" + message;
                    System.out.println("message server: " + message);
                    sendPacket(message, group);
                }else if(message.contains("<fin>")){
                    message = message.substring(5);   // User name being substract
                    String username = "";
                    String usersS;
                    //* Determining the user who has just disconnected
                    for(int i = 0; Character.isLetter(message.charAt(i)) && i < message.length(); i++) username += message.charAt(i); // Concat the username into a new string
                    System.out.println("Salio: " + username);
                    users.remove(username);
                    usersS = "<usuarios>" + users.toString(); //* Converting the array of users into a string ready to be sent
                    //* Sending packet
                    sendPacket(usersS, group);
                    try{
                        Thread.sleep(1000);
                    }catch(InterruptedException ie){}
                }
            }catch(Exception e){
                e.printStackTrace();
            }
            
        }
    }

    /**
     * Method that send a packet to the cliente
     * @param msg The message to be sent
     * @param gpo The multicast group
     */
    public static void sendPacket(String msg, InetAddress gpo){
        try {
            byte[] b = msg.getBytes();
            packet = new DatagramPacket(msg.getBytes(), msg.length(), gpo, Constants.SERVER_PTO);
            System.out.println("Mensaje " + msg +  " enviado con un ttl = " +s.getTimeToLive());
            s.send(packet);
            s.close(); 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Method that make the server connection
     * @oaram none
     * @return none
     */
    public void serverConnect(){
        try {
            if(request){
                s = new MulticastSocket(Constants.SERVER_PTO);
                Connection.selectNetworkInterface(Constants.SERVER_PTO, s, true, group); 
                ni = s.getNetworkInterface();
                request = false;
            }else{
                SocketAddress dir;
                try{
                     dir = new InetSocketAddress(Constants.GROUP,Constants.SERVER_PTO);
                }catch(Exception e){
                  e.printStackTrace();
                   return;
                }//catch
                s.joinGroup(dir, ni);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args) {
        Server server = new Server();
        server.start();
    }
}
