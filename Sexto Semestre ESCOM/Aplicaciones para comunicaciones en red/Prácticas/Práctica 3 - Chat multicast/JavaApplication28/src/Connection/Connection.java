/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Connection;

import constants.Constants;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.SocketAddress;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;
import java.util.List;
import javax.swing.JOptionPane;
import javax.swing.UIManager;

/**
 *
 * @author BrandMV
 */
public class Connection {

    /**
     * Method that shows the NIC info
     * @param netint The network Interface the user has choosen
     * @throws SocketException If was not possible to join to the group
     */
    public static void despliegaInfoNIC(NetworkInterface netint) throws SocketException {
        System.out.printf("Nombre de despliegue: %s\n", netint.getDisplayName());
        System.out.printf("Nombre: %s\n", netint.getName());
        String multicast = (netint.supportsMulticast())?"Soporta multicast":"No soporta multicast";
        System.out.printf("Multicast: %s\n", multicast);
        Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
        for (InetAddress inetAddress : Collections.list(inetAddresses)) {
            System.out.printf("Direccion: %s\n", inetAddress);
        }
        System.out.printf("\n");
     }

    /**
     * Method that will join the user to the group depending on the NI choosen
     * @param pto The server port
     * @param s The multicastSocket
     * @param server Wheter if is the server or a client
     * @param group The multicast group
     */
    
    public static void selectNetworkInterface(int pto, MulticastSocket s, boolean server, InetAddress group){
        if(server){
            try {
             BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
             int z=0;

               for (NetworkInterface netint : Collections.list(nets)){
                   if(netint.supportsMulticast()){
                         System.out.print("[Interfaz "+ ++z +"]:");
                         despliegaInfoNIC(netint);
                   }
               }//for

             System.out.print("\nElige la interfaz multicast:");
             int interfaz = Integer.parseInt(br.readLine());
             //NetworkInterface ni = NetworkInterface.getByName("eth2");
             NetworkInterface ni = NetworkInterface.getByIndex(interfaz);
             br.close();
             System.out.println("\nElegiste "+ni.getDisplayName());

             SocketAddress dir;
             try{
                  dir = new InetSocketAddress(group,pto);
             }catch(Exception e){
               e.printStackTrace();
                return;
             }//catch
             s.joinGroup(dir, ni);


         } catch (Exception e) {
             e.printStackTrace();
             System.exit(0);
         } 
        }else{
            try{
                Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
                int z=0;
                List<NetworkInterface> networks = new ArrayList<>();
                List<String> netsNames = new ArrayList<>();
                for (NetworkInterface netint : Collections.list(nets)){
                   if(netint.supportsMulticast()){
                       netsNames.add(netint.getDisplayName());
                       networks.add(netint);
                   }
               }//for
                String selectedNet = (String) JOptionPane.showInputDialog(null, "Selecciona tu interfaz multicast para conectarte","Interfaz Multicast", JOptionPane.QUESTION_MESSAGE,
                        UIManager.getIcon("OptionPane.questionIcon"),
                        netsNames.toArray(), netsNames.get(0));
                
                NetworkInterface ni = networks.get(netsNames.indexOf(selectedNet));
                SocketAddress dir;
                try{
                     dir = new InetSocketAddress(Constants.GROUP,pto);
                }catch(Exception e){
                  e.printStackTrace();
                   return;
                }//catch
                s.joinGroup(dir, ni);
            }catch (Exception e) {
                 e.printStackTrace();
                 System.exit(0);
             } 
        }
    
    }

}
