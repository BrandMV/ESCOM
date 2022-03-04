/*
    ALUMNO: Meza Vargas Brandon David.
    PRÁCTICA: Práctica No. 2
    TEMA: Arreglos de objetos
    OPCIÓN: Opción 3, mosaico de imágenes.
    FECHA: 02-nov-2020
    GRUPO: 2CM1
    MATERIA: Programación Orientada a Objetos
*/

package Practicas.Practica2;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class mosaico extends JApplet implements ActionListener{
    JButton elementos[];
    JLabel selec, l;
    Container c;
    int i;

    public mosaico(){

    }

    public void init(){
        c=getContentPane(); 
        c.setLayout(new GridLayout(4,10));  
        elementos = new JButton[40];
        for(i=0;i<40;i++){
            elementos[i] = new JButton(new ImageIcon(i+".jpg"));
            c.add(elementos[i]);
            elementos[i].addActionListener(this);
        }

              
        l=new JLabel("Tu seleccion: ");
        c.add(l);
        selec = new JLabel();
        c.add(selec);
        
    }
    public void actionPerformed (ActionEvent e){
        JButton b=(JButton)e.getSource();
        selec.setIcon(b.getIcon());
    }
    public static void main(String[] args) {
        mosaico m=new mosaico();
        m.init(); m.start();
        Frame f=new Frame("Mosaico de imágenes");
        f.add("Center",m);
        f.setSize(900,300);
     
        f.setVisible(true);
       
    }

    
}
