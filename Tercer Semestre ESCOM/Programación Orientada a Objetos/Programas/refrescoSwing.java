import java.awt.event.*;
import java.awt.*;
import java.applet.*;
import javax.swing.*;

public class refrescoSwing extends JApplet implements ActionListener{
    JButton bman, bnar, blim;
    JLabel mensaje, l;
    Container c;

    public refrescoSwing(){


    }
    public void init(){ //inicializa el applet
        c=getContentPane();             // url, path o nombre
        bman = new JButton(new ImageIcon("manzana.jpg"));
        bnar = new JButton(new ImageIcon("naranja.jpg"));
        blim = new JButton(new ImageIcon("limon.jpg"));
        mensaje = new JLabel("           ");

        bman.addActionListener(this);
        bnar.addActionListener(this);
        blim.addActionListener(this);

        c.setLayout(new BorderLayout()); //con este puedo agregar añ norte, centro, sur, este o al oeste
        c.add("West",bman); c.add("Center",bnar);
        c.add("East", blim); c.add("South", mensaje);
        //setSize(900,500)
        
    }
    public void actionPerformed (ActionEvent e){
        JButton b=(JButton)e.getSource();
        mensaje.setIcon(b.getIcon());
    }//devuelve tipo Object

    public static void main(String[] args) {
        refrescoSwing m = new refrescoSwing();
        m.init(); m.start();
        Frame f=new Frame("Maquina");
        f.add("Center",m);
        f.setSize(900,300);
        f.setVisible(true);
        

    }






}