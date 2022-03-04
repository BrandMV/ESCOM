import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FlappyPan extends JPanel implements Runnable {
   int posXave=0, posYave=200;
   int r1,r2,r3,r4;
   JLabel Imagen;
   int frame;
   ImageIcon iconos[];
   Thread hilo;

   public FlappyPan(){
      iconos=new ImageIcon[3];
      for(int i=0; i <iconos.length;i++)
         iconos[i] =new ImageIcon("C:\\Users\\PC\\Desktop\\3er Semestre ESCOM\\POO\\Programas\\Practicas\\Practica4\\ave"+(i+1)+".png");
         
      setVisible(true);
      setBounds(0,0,1000,705);	
      setLayout(null);

      add(Imagen =new JLabel(iconos[0]));
      Imagen.setBounds(posXave,posYave,100,50);
      r1= (int)(Math.random()*300);
      r2= r1+150;
      r3= (int)(Math.random()*300);
      r4= r3+150;	
      paintComponents(getGraphics());
      hilo=new Thread(this); //edo recien nacido
      hilo.start(); //edo. listo
   } 	

   public void run(){
      
      while(true)
      {
         int i=0;
         iconos[i] =new ImageIcon("C:\\Users\\PC\\Desktop\\3er Semestre ESCOM\\POO\\Programas\\Practicas\\Practica4\\ave"+(i+1)+".png");
          try{
              Thread.sleep(500); //hacemos una pausa del hilo
          }catch(Exception e){
              return;
          }
      }
  }

}
