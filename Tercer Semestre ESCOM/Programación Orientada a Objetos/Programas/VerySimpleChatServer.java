import java.io.*;
import java.net.*;
import java.util.*;
public class VerySimpleChatServer {
    ArrayList<ObjectOutputStream> clientObjectOutputStreams;
    public class ClientHandler implements Runnable {
         ObjectInputStream reader;   
         Socket sock;
         public ClientHandler(Socket clientSocket) {
           try {
             sock = clientSocket;           //Devuelve tipo InputStream, recibimos un byte a la vez
             reader = new ObjectInputStream(sock.getInputStream());  
             //System.out.println("Servidor reader (" + reader+")");       
           } catch(Exception ex) {
                System.out.println("Exce Servidor reader " + ex);
                ex.printStackTrace();
             }
          } // close constructor
        public void run() {
           Object obj;  
           try {
             while (true) {
		obj = (Object) reader.readObject();
                //System.out.println("read " + pub);
                tellEveryone(obj);
             }
           } catch(Exception ex) {ex.printStackTrace();}

       } // close run
   } // close inner class
     public static void main (String[] args) {
         new VerySimpleChatServer().go();
    }
     public void go() {
      clientObjectOutputStreams = new ArrayList<ObjectOutputStream>();
       try {
       ServerSocket serverSock = new ServerSocket(5000);
       while(true) {
          Socket clientSocket = serverSock.accept();   //accept bloquea el programa y se desbloquea cuando se conecta un cliente
                 //OutputStream renvia un byte a la vez
          ObjectOutputStream writer = new ObjectOutputStream(clientSocket.getOutputStream()); //usa el flujo de salida para crear un objeto de tipo OutputStream       
          clientObjectOutputStreams.add(writer); //guarda el flujo de salida para objetos en el arraylist

       Thread t = new Thread(new ClientHandler(clientSocket)); //se le da un objeto de una clase que implemente la interfaz Runnable de forma general
                                                                //particularmente un objeto de la clase Client Handler
       t.start(); //edo. listo
       System.out.println("got a connection");
     }
       // now if I get here I have a connection        
      }catch(Exception ex) {
         ex.printStackTrace();
      }
   }
   public void tellEveryone(Object obj) {
      Iterator it = clientObjectOutputStreams.iterator(); //recorremos el contenedor
      while(it.hasNext()) { //si hay un elemento en el contenedor que no hayamos visitado, en el ciclo mandamos a cada cliente conectado el objeto obj
        try {
           ObjectOutputStream writer = (ObjectOutputStream) it.next();
           writer.writeObject(obj);//se escribe en la red el objeto, a ese cliente le mandamos por la red el objeto, lo hacemos para cada flujo de salida 
                                    //en el arraylist
           writer.flush();  //se vacia el flujo de salida
         } catch(Exception ex) {
              ex.printStackTrace();
         }
      
       } // end while   
   } // close tellEveryone
}
       