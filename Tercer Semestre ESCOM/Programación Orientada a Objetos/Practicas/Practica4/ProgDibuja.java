/*
ALUMNO: Meza Vargas Brandon David.
PRÁCTICA: Práctica No. 4.
TEMA: Hilos.
OPCIÓN: Opción 4, Animación con sprites.
FECHA: 03-dic-2020
GRUPO: 2CM1
MATERIA: Programación Orientada a Objetos

*/
import java.awt.*; 
import java.awt.event.*;
import java.awt.image.*; 
import java.io.*;
import javax.imageio.*;
import javax.swing.*;

public class ProgDibuja extends JFrame implements Runnable{

Thread hilo, hilof;
Graphics g;
BufferedImage birds[], fondos[];
BufferedImage spriteSheet=null;
int cta=0, x=0, longi=0, ctaf=0;
final int width = 34, height = 42;
final int rows = 3, cols = 1;
private BufferedImage getSprite(BufferedImage spriteSheet, int i, int j, 
         int width, int height){      
    return  spriteSheet.getSubimage(j , i , width, height);
}

public ProgDibuja(){
   super("Flappy Bird");
   try {   
       spriteSheet = ImageIO.read(new File("C:\\Users\\PC\\Desktop\\3er Semestre ESCOM\\POO\\Programas\\Practicas\\Practica4\\Flappy-Graphics.png")); 
   }catch(IOException e){  System.out.println("Image not found"); }
   fondos = new BufferedImage[2]; 
   birds = new BufferedImage[3];  
   fondos[0] =getSprite(spriteSheet,0, 0, 290, 512);  //dia
   fondos[1] =getSprite(spriteSheet,0, 0, 290, 512); //noche
   birds [0] =getSprite(spriteSheet,750, 220, 50, 50);//alas arriba
   birds [1] =getSprite(spriteSheet,800, 220, 50, 50);//alas enmedio
   birds [2] =getSprite(spriteSheet,850, 220, 50, 50);//alas abajo

 
   setSize(290, 510); setVisible(true);
   setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   hilo=new Thread(this); //edo recien nacido
   hilo.start(); //edo. listo
}
public void paint(Graphics g){
   
    g.drawImage(fondos[cta], x, 0, this);

    g.drawImage(birds[ctaf], x, 250, this);
    
}
@Override
    public void run(){
            while(true){
                    try{
                        cta++;
                        if(cta==3)
                            cta=0;
                        this.repaint();
                        x+=10;
                        if(x>this.getWidth()-34)
                            x=0;
                        hilo.sleep(100);  
                    }
                    catch(Exception e){
                        return;
                    }
                
            }          
}

public static void main(String[] args){ ProgDibuja pd=new  ProgDibuja(); }

}

