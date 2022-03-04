package guia1;
/*
Modelado:
---------------------
coversion
---------------------
pd
dp
cant
res
---------------------
conversion()
actionPerformed(...)
---------------------
*/
import java.awt.event.*;
import java.awt.*;


import java.awt.*;
public class conversion extends Panel implements ActionListener{
    Button pd,dp;
    TextField cant;
    Label res;
    public conversion(){

        cant=new TextField();
        add(cant);
        pd= new Button("Pesos a Dolares");
        add(pd);
        pd.addActionListener(this);
        dp= new Button("Dolares a Pesos");
        add(dp);
        dp.addActionListener(this);
        res=new Label("                           ");
        add(res);

    }
    public void actionPerformed(ActionEvent e){
        Button btn=(Button)e.getSource();
        Double cantidad;
        cantidad=Double.parseDouble(cant.getText());
        if(btn == pd){
            res.setText(String.valueOf(cantidad/20+" dolares")); //el valor de un dolar se tomo como a 20 pesos
        }
        if(btn == dp){
            res.setText(String.valueOf(cantidad*20+" pesos")); //el valor de un dolar se tomo como a 20 pesos
        }
    }
    public static void main(String[] args) {
        Frame f= new Frame("Conversion");
        f.add("Center", new conversion());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
    }
}
