import java.io.*;
import java.net.*;

public class IncomingReader implements Runnable{
    private LeeRed lr;
    private ObjectInputStream oisNet; //sirve para recibir objetos
    public IncomingReader(LeeRed lr, ObjectInputStream oisNet){
        this.lr=lr;
        this.oisNet=oisNet;

    }

    public void run() {
        Object obj=null;
        int j;
        System.out.println("run");
        for(;;){ //ciclo infinito
            j=0;
            try {
                obj=oisNet.readObject(); //trata de leer un flujo de entrada
            } catch (IOException e) {
                System.out.println("IO ex "+e);
                j=1;
            }catch(ClassNotFoundException ex){
                System.out.println("Class no found "+ex);
                j=1;
            }
            if (j==0){
                lr.leeRed(obj);
                //parti un objeto de tipo gatoRed
                //gral. un objeto de una clase que implementa la interfaz LeeRed (polimorfismo)
            }
        }
        
    }
    
}
