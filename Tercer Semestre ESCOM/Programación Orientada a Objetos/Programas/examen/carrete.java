package examen;

public class carrete {
    int cable;
    public carrete(){
        this.cable=100;
    }

    public void cortar(int cant){
        if(hay(cant)){
            cable-=cant;
        } 
        else  
            System.out.println("No puedes comprar mas de "+cable+ " metros de cable");
        

    }
    public Boolean hay(int cant){
        if(cant<=cable)
            return true;
        else   
            return false;
    }
    public void cantCarrete(){
        System.out.println("Quedan "+this.cable+" metros de cable");
    }
    
    public static void main(String[] args) {
        carrete c;
        Boolean b;
        c= new carrete();

        b=c.hay(120);
        System.out.println(b);
        c.cantCarrete();
        c.cortar(120);
        c.cantCarrete();

        //cortamos otros 30 metros del carrete
        b=c.hay(30);
        System.out.println(b);
        c.cantCarrete();
        c.cortar(20);
        c.cantCarrete();
        

  
    }
}
