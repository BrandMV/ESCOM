/*
Modelado:
---------------------
minutos
---------------------
min
btn
dias
hrs
---------------------
minutos()
actionPerformed(...)
---------------------
*/

package guia1;

import java.awt.event.*;
import javax.swing.JTextField;
import java.awt.*;
import java.applet.*;

public class minutos extends Panel implements ActionListener{

    TextField min;
    Button btn;
    Label dias,hrs;

    public minutos(){
        min= new TextField();
        add(min);
       
        dias=new Label("                      ");
        add(dias);
        hrs=new Label("                       ");
        add(hrs);
        btn=new Button("Calcula");
        add(btn);
        btn.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
        int ht,dt,minu;
        Button b = (Button)e.getSource();

        minu=Integer.parseInt(min.getText());
        dt=minu/1440;
        ht=minu/60;
        dias.setText(String.valueOf(dt)+" días");
        hrs.setText(String.valueOf(ht)+ " horas");
    }


    public static void main(String[] args) {
        Frame f= new Frame("Minutos");
        f.add("Center", new minutos());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
}
