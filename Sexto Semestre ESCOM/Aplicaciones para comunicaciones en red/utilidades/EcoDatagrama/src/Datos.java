import java.io.Serializable;
/**
 *
 * @author axele
 */
public class Datos implements Serializable {
    int np;
    byte[] datos;
    
    public Datos(int np, byte[] datos){
        this.np=np;
        this.datos=datos.clone();
    }//constructor
    
    int getnp(){
        return this.np;
    }
    
    byte[] getdatos(){
        return this.datos.clone();
    }
}
