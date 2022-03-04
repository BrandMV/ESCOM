import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class cuentaSegundos extends JFrame implements Runnable{
    int cont;
    JLabel seg;
    Thread printerThread;
    int lim;
    public cuentaSegundos(int lim){
        this.lim=lim;
        this.cont=0;
        setLayout(null);
        setSize(100, 100); setVisible(true);
        
        seg = new JLabel("HOLA");
        seg.setBounds(50,30,20,20);
        this.add(seg);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
        printerThread=new Thread(this); //edo recien nacido
        printerThread.start(); //edo. listo
    }
    
    public void run() {
        while(cont<=lim)
        {
           System.out.println(cont);  
          
            try {
                seg.setText(""+cont);
                this.repaint();
                 cont+=1;
                Thread.sleep(1000);
            } catch (Exception e) {
                return;
            }
        }
    }

    public static void main(String[] args) {
        cuentaSegundos cs= new cuentaSegundos(10);
    }
}
