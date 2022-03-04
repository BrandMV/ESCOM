
import java.io.*;
import java.net.*;
import javax.swing.*;


public class Red {
    private Socket cliente;
    private ObjectInputStream oisNet;
    private ObjectOutputStream oosNet;
    private int puerto=5000;
    //interfaz
    private LeeRed lr;
    public Red(LeeRed lr){
        this.lr=lr;
        setUpNetworking();
    }

    public void setUpNetworking(){
        int i=0;
        String host=JOptionPane.showInputDialog("Escriba dir. IP", "localhost");
        while(i==0){
            System.out.println("Esperando por el servidor..."); i=1;
            try{
                cliente=new Socket(host, puerto);
            }catch(IOException e){
                System.out.println("Fallo creacion del Socket"); i=0;
            }
        }
        System.out.println("Conectando al servidor.");
        try {
            //InputStream recibe un byte a la vez
            oisNet = getOISNET(cliente.getInputStream()); //recibe objetos y esos objetos pueden venir de la red
            //OutputStream enviar un byte a la vez
            oosNet = getOOSNET(cliente.getOutputStream()); //manda objetos a la red
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Error al crear los flujos de objeto "+e);
        }
        //gral. un objeto de una clase que implemente la interfaz Runnable
        (new Thread(new IncomingReader(lr, oisNet))).start();
    }

    //flush meadows
    public void escribeRed(Object obj){
        try {
            oosNet.writeObject(obj); //
            oosNet.flush();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    ObjectOutputStream getOOSNET(OutputStream os) throws IOException{
        return new ObjectOutputStream(os);
    }
    ObjectInputStream getOISNET(InputStream is)throws IOException{
        return new ObjectInputStream(is);
    }
}
