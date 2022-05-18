
import java.io.Serializable;

class Objeto implements Serializable{
  String x;
  float y;
  int z;

  public Objeto(String x, float y, int z){
      this.x=x;
      this.y=y;
      this.z=z;
  }
  public String getX(){
      return this.x;
  }
   public float getY(){
       return this.y;
   }
   
   public int getZ(){
       return this.z;
   }
}//class
