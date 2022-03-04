/*
ALUMNO: Meza Vargas Brandon David
GRUPO: 2CM1
Problema: 3
GUI

3.-Codificar un applet que tenga un botón, tres campos de entrada y una etiqueta. 
Un campos de entrada es para las horas, otro para el numero de minutos y otro mas para el numero de 
segundos imprima el total de segundos transcurridos en la etiqueta si se presiona el boton. 
Ejemplo si se le dan 18 hrs con 3 min y 20 segundos el programa debe imprimir 65000 segundos (18*3600+3*60+20).

Modelado:
---------------------
guiSegundos
---------------------
hrs
min
b
s
lbl
---------------------
init()
actionPerformed(...)
---------------------
*/


import java.awt.event.*;
import java.awt.*;
import java.applet.*;

public class gui extends Applet implements ActionListener{
    TextField hrs,min,s;
    Button b;
    Label lbl;
    
    public void init(){
        
        hrs=new TextField();
        add(hrs);
        min=new TextField();
        add(min);
        s=new TextField();
        add(s);
        b=new Button("Segundos");
        add(b);
        lbl= new Label("                            ");
        add(lbl);

        b.addActionListener(this);
    }

   
    public void actionPerformed(ActionEvent e){
        int horas, minu, segu, st;
        String seg;
        Button b = (Button)e.getSource();

        horas=Integer.parseInt(hrs.getText());
        minu=Integer.parseInt(min.getText());
        segu=Integer.parseInt(s.getText());

        st=horas*3600+minu*60+segu;
        seg= String.valueOf(st);
        lbl.setText(seg + " segundos en total");
      
    }

}
