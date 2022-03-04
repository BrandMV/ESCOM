package guia1;
/*
Modelado:
---------------------
mayor
---------------------
b1
b2
b3
et
---------------------
frutas()
actionPerformed(...)
---------------------
*/

import java.awt.event.*;
import java.awt.*;

public class frutas extends Panel implements ActionListener{
    Button b1,b2,b3;
    Label et;
    public frutas(){
        b1 = new Button("Manzana");
        b2 = new Button("Limon");
        b3 = new Button("Naranja");
        add(b1);    add(b2);    add(b3);
        b1.addActionListener(this); b2.addActionListener(this);
        b3.addActionListener(this);

        et = new Label("                ");
        add(et);
    }

    public void actionPerformed(ActionEvent e){
        Button btn = (Button)e.getSource();
        et.setText(btn.getLabel());
    }

    public static void main(String[] args) {
        Frame f= new Frame("Problema 10");
        f.add("Center", new frutas());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
    
}
