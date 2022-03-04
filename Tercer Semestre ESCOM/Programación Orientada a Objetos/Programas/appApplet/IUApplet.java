package appApplet;

import java.awt.event.*;
import java.awt.*;
import java.applet.*;


                          //IS_A                      //interfaz
public class IUApplet extends Applet implements ActionListener {
    Button b;
    TextField t;
  
    public void init() {
        t = new TextField(10);
        add(t);     //lo añado al contenedor
        b=new Button("Muestra");
        add(b);
        b.addActionListener(this); //registro, this es el objeto que se usa para llamar al metodo dentro del cual se esncuentra this
                                    //Aqui this esta dentro del metodo init, this es un objeto de tipo applet, aqui concretamente tipo IUApplet
                                    //el parametro de addactionliostener debe se un onjeto de la clase que implemente actionListener
        add(b);
        //b es la fuente de eventos
        //addActionListener oficina suscripciones
        //this escucha
    }

    public void actionPerformed(ActionEvent e){
        showStatus(t.getText()); //muestra nuestro texto en el campo de entrada en la zona de estado
        //cadena 
    }

    
}
    

