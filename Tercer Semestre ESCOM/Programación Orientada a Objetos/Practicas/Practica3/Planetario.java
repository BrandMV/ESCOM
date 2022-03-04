/*
    ALUMNO: Meza Vargas Brandon David.
    PRACTICA: Practica No. 3
    TEMA: Java3D
    OPCIÓN: Opción 1, Sistema Solar (Planetario).
    FECHA DE ENTREGA: 
    GRUPO: 2CM1
    MATERIA: Programacion Orientada a Objetos
*/



import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.image.TextureLoader;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import java.awt.*;
import java.io.File;
import javax.swing.*;
import java.util.*;

        

public class Planetario {
    
    public Planetario(){
        
        BranchGroup group = new BranchGroup();
        Appearance appsol = new Appearance();
        Appearance appearth = new Appearance();
        Appearance appvenus = new Appearance();
        Appearance appmercurio = new Appearance();
       // String localPath=new File("").getAbsolutePath()+"\\images\\";
        
        TextureLoader tex=new TextureLoader("tierra.jpg", null);
        appearth.setTexture(tex.getTexture());
        tex=new TextureLoader("sol.jpg",null);
        appsol.setTexture(tex.getTexture());
        tex=new TextureLoader("venus.jpg",null);
        appvenus.setTexture(tex.getTexture());
        tex=new TextureLoader("mercurio.jpg",null);
        appmercurio.setTexture(tex.getTexture());
        
        Sphere earth = new Sphere(0.045f, Primitive.GENERATE_NORMALS | Primitive.GENERATE_TEXTURE_COORDS, 50, appearth);
        Sphere sol = new Sphere(0.35f, Primitive.GENERATE_NORMALS | Primitive.GENERATE_TEXTURE_COORDS, 32, appsol);
        Sphere venus = new Sphere(0.030f, Primitive.GENERATE_NORMALS | Primitive.GENERATE_TEXTURE_COORDS, 32, appvenus);
        Sphere mercurio = new Sphere(0.025f, Primitive.GENERATE_NORMALS | Primitive.GENERATE_TEXTURE_COORDS, 32, appmercurio);
        
        TransformGroup earthRotXformGroup = Posi.rotate(earth, new Alpha(-1,1250));
        TransformGroup solRotXformGroup = Posi.rotate(sol, new Alpha(-1,1250));
        TransformGroup venusRotXformGroup = Posi.rotate(venus, new Alpha(-1,1250));
        TransformGroup mercurioRotXformGroup = Posi.rotate(mercurio, new Alpha(-1,1250));
        
        TransformGroup earthTransXformGroup= Posi.translate(earthRotXformGroup, new Vector3f(0.0f,0.0f,0.7f));
        TransformGroup earthRotGroupXformGroup = Posi.rotate(earthTransXformGroup, new Alpha(-1, 5000));
        
        TransformGroup venusTransXformGroup= Posi.translate(venusRotXformGroup, new Vector3f(0.0f,0.0f,.5f));
        TransformGroup venusRotGroupXformGroup = Posi.rotate(venusTransXformGroup, new Alpha(-1, 2000));
        
        TransformGroup mercurioTransXformGroup= Posi.translate(mercurioRotXformGroup, new Vector3f(0.0f,0.0f,0.3f));
        TransformGroup mercurioRotGroupXformGroup = Posi.rotate(mercurioTransXformGroup, new Alpha(-1, 1000));
        
        group.addChild(earthRotGroupXformGroup);
        group.addChild(venusRotGroupXformGroup);
        group.addChild(mercurioRotGroupXformGroup);
        group.addChild(solRotXformGroup);
        
        GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
        Canvas3D canvas = new Canvas3D(config); canvas.setSize(600,600);
        SimpleUniverse universe=new SimpleUniverse(canvas);
        universe.getViewingPlatform().setNominalViewingTransform();
        universe.addBranchGraph(group);
        JFrame f = new JFrame("Planetario");
       
        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        f.add(canvas); f.pack(); f.setVisible(true);
    }
    
    
    public static void main(String[] args) {
        new Planetario();
    }
    
}
