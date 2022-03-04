package guia1;
/*
Modelado:
---------------------
mayor
---------------------
n1
n2
n3
b
mayor
---------------------
mayor()
actionPerformed(...)
---------------------
*/

import java.awt.event.*;
import java.awt.*;

public class mayor extends Panel implements ActionListener{
    TextField n1,n2,n3;
    Button b;
    Label mayor;
    public mayor(){
        n1 = new TextField();
        n2 = new TextField();
        n3 = new TextField();
        add(n1); add(n2); add(n3);

        b= new Button("Ver mayor de los numeros");
        add(b); b.addActionListener(this);

        mayor = new Label("                 "); add(mayor);
    }

    public void actionPerformed(ActionEvent e){
        Button b=(Button)e.getSource();
        int num1 = Integer.parseInt(n1.getText());
        int num2 = Integer.parseInt(n2.getText());
        int num3 = Integer.parseInt(n3.getText());

        if(num1 > num2)
            if(num1 > num3)
                mayor.setText("El mayor es "+num1);
            else
                mayor.setText("El mayor es "+num3);
        else if(num2 > num3)
            mayor.setText("El mayor es "+num2);
            else
                mayor.setText("El mayor es "+num3);
    }

    public static void main(String[] args) {
        Frame f= new Frame("Mayor de tres numeros");
        f.add("Center", new mayor());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
}
