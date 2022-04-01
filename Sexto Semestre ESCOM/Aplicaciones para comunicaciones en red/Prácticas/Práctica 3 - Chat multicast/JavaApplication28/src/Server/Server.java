/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.SocketAddress;
import java.util.Collections;
import java.util.Enumeration;

/**
 *
 * @author BrandonMV
 */
public class Server {
 
    public static void main(String[] args) {
        try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
        int z=0,pto= 9930,pto_dst=9931;
          for (NetworkInterface netint : Collections.list(nets)){
              System.out.print("[Interfaz "+ ++z +"]:");
             despliegaInfoNIC(netint);
          }//for
        System.out.print("\nElige la interfaz multicast:");
        int interfaz = Integer.parseInt(br.readLine());
        //NetworkInterface ni = NetworkInterface.getByName("eth2");
        NetworkInterface ni = NetworkInterface.getByIndex(interfaz);
        br.close();
        System.out.println("\nElegiste "+ni.getDisplayName());

          
          MulticastSocket s = new MulticastSocket(pto);
          s.setReuseAddress(true);
          s.setTimeToLive(255);
          InetAddress gpo = InetAddress.getByName("230.1.1.1");
          //InetAddress gpo = InetAddress.getByName("ff3e:40:2001::1");
          SocketAddress dir;
            try{
                 dir = new InetSocketAddress(gpo,pto);
            }catch(Exception e){
              e.printStackTrace();
               return;
            }//catch
            s.joinGroup(dir, ni);
            //s.joinGroup(gpo);
            String msj="Mensaje desde el servidor 3****";
            byte[] b = msj.getBytes();
            System.out.println("Servicio iniciado.. comienza envio de anuncios");
            for(;;){
              DatagramPacket p = new DatagramPacket(b,b.length,gpo,pto_dst);
              s.send(p);
                System.out.println("Mensaje enviado con un ttl="+s.getTimeToLive());
              try{
                  Thread.sleep(5000);
              }catch(InterruptedException ie){}
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
