package guia1;

import java.awt.event.*;
import java.awt.*;
/*
Modelado:
---------------------
coversion
---------------------
igual
btn
t1
t2
---------------------
iguales()
actionPerformed(...)
---------------------
*/
public class iguales extends Panel implements ActionListener{
    Label igual;
    Button btn;
    TextField t1,t2;

    public iguales(){
        t1 = new TextField();
        t2 = new TextField();
        add(t1); add(t2);
        btn = new Button("Comparar");
        add(btn);
        btn.addActionListener(this);
        igual= new Label("                      ");
        add(igual);
    }

    public void actionPerformed(ActionEvent e){
        Button btn = (Button)e.getSource();

        if(t1.getText().equals(t2.getText()))
            igual.setText("Son iguales");
        else
            igual.setText("No son iguales");

    }
    public static void main(String[] args) {
        Frame f= new Frame("Iguales");
        f.add("Center", new iguales());
        f.setSize(300,300); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
    
}
