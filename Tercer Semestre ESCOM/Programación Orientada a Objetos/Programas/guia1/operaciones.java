package guia1;
/*
Modelado:
---------------------
operaciones
---------------------
n1
n2
suma
resta
mult
div
res
---------------------
operaciones()
actionPerformed(...)
---------------------
*/

import java.awt.event.*;
import java.awt.*;

public class operaciones extends Panel implements ActionListener{
    TextField n1,n2;
    Button suma,resta,mult,div;
    Label res;

    public operaciones(){
        n1 = new TextField(0);
        n2 = new TextField(0);
        add(n1); add(n2);

        suma= new Button("+");
        resta= new Button("-");
        mult= new Button("*");
        div= new Button("/");
        add(suma); add(resta); add(mult); add(div);
        suma.addActionListener(this); resta.addActionListener(this);
        mult.addActionListener(this); div.addActionListener(this);

        res= new Label("              ");
        add(res);
    }

    public void actionPerformed(ActionEvent e){
        Button b=(Button)e.getSource();

        if(b==suma)
            res.setText(String.valueOf(Double.parseDouble(n1.getText()) + Double.parseDouble(n2.getText())));
        if(b==resta)
            res.setText(String.valueOf(Double.parseDouble(n1.getText()) - Double.parseDouble(n2.getText())));
        if(b==mult)
            res.setText(String.valueOf(Double.parseDouble(n1.getText()) * Double.parseDouble(n2.getText())));
        if(b==div)
            res.setText(String.valueOf(Double.parseDouble(n1.getText()) / Double.parseDouble(n2.getText())));
    }

    public static void main(String[] args) {
        Frame f= new Frame("Operaciones");
        f.add("Center", new operaciones());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
}
