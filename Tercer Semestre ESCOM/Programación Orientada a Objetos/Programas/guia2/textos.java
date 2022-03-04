import java.awt.*;
import java.awt.event.*;
import java.util.Scanner;

import javax.swing.*;

public class textos implements Runnable{
    Thread hilo;
    String [] c;


    public textos(String [] c){
        this.c=c;

        hilo=new Thread(this); //edo recien nacido
        hilo.start(); //edo. listo
    }

    @Override
    public void run() {
        for(int i=0;i<=c.length;i++){
            try {
                System.out.println(c[i]);
                Thread.sleep(1000);
                
            } catch (Exception e) {
                return;
            }
        }
    }

    public static void main(String[] args) {
        String [] c={"Hola", "amigo","como","estas","?"};
        textos t=new textos(c);
    }

    
}
