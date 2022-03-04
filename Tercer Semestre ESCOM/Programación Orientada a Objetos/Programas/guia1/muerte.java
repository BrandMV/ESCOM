package guia1;

/*
Modelado:
---------------------
muerte
---------------------
edad
muerte
año
---------------------
muerte()
actionPerformed(...)
---------------------
*/
import java.awt.event.*;
import java.util.Calendar;
import java.awt.*;

public class muerte extends Panel implements ActionListener{
    TextField edad;
    Button muerte;
    Label año;
    public muerte(){
        edad = new TextField(); add(edad);
        muerte = new Button("Calcular año de muerte");
        add(muerte); muerte.addActionListener(this);
        año = new Label("                             "); add(año);
     
    }

    public void actionPerformed(ActionEvent e){
        int ed,añom, a;
        Calendar fechaact=Calendar.getInstance();
        int añoact=fechaact.get(Calendar.YEAR);
        ed= Integer.parseInt(edad.getText());

        a=77-ed;
        añom=añoact+a;
        año.setText("Morira en " + añom);
    }

    public static void main(String[] args) {
        Frame f= new Frame("Año de muerte");
        f.add("Center", new muerte());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
    
}
