import java.io.*;
class Objeto implements Serializable{
	int x;
	float y;
        String z;
	Objeto(int x, float y, String z){
		this.x = x;
		this.y = y;
                this.z = z;
	}

    public int getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public String getZ() {
        return z;
    }
               
        
	
	}