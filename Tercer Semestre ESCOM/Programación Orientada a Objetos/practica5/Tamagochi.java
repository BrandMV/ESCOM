import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.image.*;
import javax.media.j3d.*;
import javax.vecmath.*;

//sudo javac -cp .:MS3DLoader.jar:j3d-vrml97.jar:portfolio.jar Tamagochi.java
//sudo java -cp .:MS3DLoader.jar:j3d-vrml97.jar:portfolio.jar Tamagochi
public class Tamagochi extends JFrame {
private Canvas3D canvas3D;
private Appearance ap;
private static Texture texture;

private JPanel jp;
private JButton bcomer;
private JLabel jl;
private JProgressBar progressBar = new JProgressBar();
private EventHandler eh; 
private PalSliders pals;

BranchGroup c=new BranchGroup();

Body b;
BodyZoey bz;
BodyBob bb;
Stan stan;
Movible movi;
Esfera e;
Comida food;
int val;
int turno=0;
int avatar= 2;
private String nombres[][] = {
{"Arizona.jpg", "caraenfermo.jpg"},
{"carafeliz.jpg", "caraenfermo.jpg"},
{"carafeliz.jpg", "caraenfermo.jpg"},
{"bob-esponja.jpg", "bobEnf.jpg"},
{"cabeza.png", "cabezamal.png"},
{"carafeliz.png", "caraenfermo.jpg"},
};
public Tamagochi(){
   super("Tamagochi 3D");
   val=0;
   setResizable(true); setSize(600, 700);
   GraphicsConfiguration config =     
   SimpleUniverse.getPreferredConfiguration();
   canvas3D = new Canvas3D(config);
   canvas3D.setBounds(0,0, getWidth(), getHeight());
   eh = new EventHandler();
   pals=new PalSliders(9, new GridLayout(9, 1),  new ManejaCambioInt());  
   bcomer=new JButton("Comer");
   bcomer.addActionListener(eh);
   jl=new JLabel("Hambre");
   progressBar.setValue(0);
   jp=new JPanel();
   jp.add(jl); jp.add(progressBar);
   jp.add(bcomer); jp.add(pals);
   add("North", jp); 
   add("South", canvas3D);
   setup3DGraphics();
   setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
   setVisible(true);
}
void setup3DGraphics(){
   BranchGroup group=null; 
   DirectionalLight light1;
   food=new Comida(c);
   String ava = JOptionPane.showInputDialog(
                "Escriba num avatar (0 - 5)", "2");
   avatar=Integer.parseInt(ava);
   SimpleUniverse universe = new SimpleUniverse(canvas3D);
   universe.getViewingPlatform().setNominalViewingTransform();
   if(avatar== 0){
	movi=new Esfera(this);
        movi.changeTextureCab(texture, "Arizona.jpg");
        group = movi.myBody();
   }
   if(avatar== 1){
	movi=new Esfera(this);
        movi.changeTextureCab(texture, "carafeliz.jpg");
        group = movi.myBody();
   }
   if(avatar== 2){
      movi=new Body(-0.4f,0.0f,0.0f,"",true, this, "Avatar1");
      //movi.changeTextureCab(texture, "carafeliz.jpg");
      //group = movi.myBody();
      group = Posi.escatrans1(movi.myBody(), new Vector3f(0.0f, -0.3f, 0.0f),
                          new Vector3d(0.05f, 0.05f, 0.05f));
   }
   if(avatar== 3){
      movi=new BodyBob(-0.4f, -0.3f,0.0f,"",true, this, "bob-esponja.jpg");
      group = movi.myBody();
   }
   if(avatar== 4){
      movi=new BodyZoey(-0.4f, -0.3f,0.0f,"",true, this, "cabeza.png");
      group = Posi.escatrans1(movi.myBody(), new Vector3f(0.3f, -0.1f, 0.0f),
                          new Vector3d(1.4f, 1.4f, 1.4f));
      //group = movi.myBody();
   }
   if(avatar== 5){
      movi=new Stan(-0.4f,0.0f, 0.0f,"",true, this, "Avatar1", null);
      group = Posi.escatrans1(movi.myBody(), new Vector3f(0.0f, -.3f, 0.0f),
                          new Vector3d(0.6f, 0.6f, 0.6f));   
   }
   c.setCapability(BranchGroup.ALLOW_CHILDREN_READ);
   c.setCapability(BranchGroup.ALLOW_CHILDREN_WRITE);
   c.setCapability(BranchGroup.ALLOW_CHILDREN_EXTEND);
   c.setCapability(BranchGroup.ALLOW_DETACH);
   c.addChild(group);
   BoundingSphere bounds =new BoundingSphere(new Point3d(0.0, 0.0, 0.0), 100.0);
   Background fondo=new Background();
   fondo.setColor(1.0f,1.0f,1.0f);
   fondo.setApplicationBounds(bounds);
   c.addChild(fondo);
   Color3f light1Color = new Color3f(1.0f, 1.0f, 1.0f);
   
   Vector3f light1Direction = new Vector3f(4.0f, -7.0f, -12.0f);
   light1 = new DirectionalLight(light1Color, light1Direction);
   light1.setInfluencingBounds(bounds);
   
   group.addChild(light1);
   universe.addBranchGraph(c);
}
public static void main(String[] args) { new Tamagochi(); }
class ManejaCambioInt implements CambioInt {
       public void cambio(int n, float sval){
        if(n==0){ movi.giraTron(sval); }
	if(n==1){ movi.giraHI(sval); }
        if(n==2){ movi.giraHD(sval); }
        if(n==3){ movi.giraBD(sval); }
        if(n==4){ movi.giraBI(sval); }
        if(n==5){ movi.giraPUD(sval); }
        if(n==6){ movi.giraPDD(sval); }
        if(n==7){ movi.giraPUI(sval); }
        if(n==8){ movi.giraPDI(sval); }
       }
    }
class EventHandler implements ActionListener {  
  public void actionPerformed(ActionEvent e1) {  
     JButton btn=(JButton)e1.getSource();
     if(btn==bcomer){ 
	val=100-val;
        turno=1-turno;
        System.out.println("Tamagochi come 2#### "+val);    
        food.comer();
        movi.changeTextureCab(texture, nombres[avatar][turno]); 
        progressBar.setValue(val);
     }
  }
}
}

