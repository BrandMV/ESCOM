package jaava3d;

import com.sun.j3d.utils.geometry.ColorCube;
import javax.media.j3d.*;
import javax.vecmath.*;


public class ejemplo3d{
    public ejemplo3d(){
        SimpleUniverse universe = new SimpleUniverse();
        BranchGroup group= new BranchGroup();
        group.addChild(new ColorCube(0.3));
        universe.getViewingPlatform().setNominalViewingTransform();
        universe.addBranchGraph(group);

    }

    public static void main(String[] args) {
        new ejemplo3d();
    }
    
}
