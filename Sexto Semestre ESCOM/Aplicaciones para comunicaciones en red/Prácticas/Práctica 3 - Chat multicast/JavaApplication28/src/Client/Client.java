/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import Connection.Connection;
import GUI.Chatss;
import constants.Constants;
import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author BrandonMV
 */
public class Client extends Thread{
    private ArrayList<String> users;
    private static MulticastSocket s;
    private ObjectInputStream ois;
    private ByteArrayInputStream bais;
    private byte[] buffer;
    private InetAddress group;
    //private byte[] data;
    private String message; //*Message to be sent to the server
    private static Chatss c;

    /**
     * Client thread that will be checking if is reading case o writing case
     */
    @Override
    public void run(){
        try {
            System.out.println("Cliente");
            s = new MulticastSocket(Constants.SERVER_PTO);
            String userName = c.getUserName();
            group = InetAddress.getByName(Constants.GROUP);
            //* Joining to the multicast group
            Connection.selectNetworkInterface(Constants.SERVER_PTO, s, false, group);
            
            //String ini = String.format(Constants.USER_JOINED_FORMAT, userName);
            //* Indicating the user connection
            String ini = "<inicio>" + userName;
            System.out.println("bytes " + ini.getBytes() + " length " + ini.length());
            //System.out.println("bytes " + ini2.getBytes() + " length " + ini2.length());
            DatagramPacket packet = new DatagramPacket(ini.getBytes(), ini.length(), group, Constants.SERVER_PTO);
            //* Sending the client who has just joined
            s.send(packet);

            //* For ever
            for(;;){
                //*If operation is equals 1 means that it'll write
                if(c.getOp() == 1){
                    //* If user is disconnected
                    if(!c.getConnected()){
//                        System.err.println("Conectado igual: " + c.getConnected());
                        message = String.format(Constants.USER_DISCONNECTED_FORMAT, userName);
                    }else{
                        //* If is the tab 0 means that the message is to the general room
                        if(c.getTab() == 0){
                            message = String.format(Constants.MESSAGE_FORMAT, userName, c.getCurrentMsg());
                        }else{
                            //* If tab is not 0 the message is a private one
                            message = String.format(Constants.PRIVATE_MESSAGE_FORMAT, userName, c.getReciever(c.getTab()), c.getCurrentMsg());
                        }
                    }
                    //* Sending the message wether a general or a private message
                    packet = new DatagramPacket(message.getBytes(), message.length(), group, Constants.SERVER_PTO);
                    s.send(packet);
                    c.setOp(0);
                    
                }else if(c.getOp() == 0){ //*We have to read
                    s.setSoTimeout(100);
                    try {
                        byte[] data = new byte[Constants.BUFFER];
                        DatagramPacket packetr = new DatagramPacket(data, data.length);
                        s.receive(packetr);
                        byte[] b = packetr.getData();
                        String nm = new String(b);
                        System.err.println("Mensaje" + nm +  " leido con un ttl = " +s.getTimeToLive());
                        c.newMessage(nm);
                    } catch (Exception e) {
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args) {
        Client cl = new Client();
        c = new Chatss(0);
        cl.start();
    }
}
