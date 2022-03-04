/*
ALUMNO: Meza Vargas Brandon David
GRUPO: 2CM1
Problema: 1

1.- Modelar un Carrete (o rollo) de cable

-suponga que cada carrete viene con 100 m de cable

-el cable solo se vende al menudeo por metro (o sea no por carrete)

-Si hay suficiente cable entonces se debe cortar del carrete la cantidad de cable que pida el cliente

Modelado:
-----------------
carrete            
-----------------
cable
cant
-----------------
cortar(...)
cantCarrete(...)
hay(...)
-----------------

*/

package examen;

public class carrete {
    int cable;
    public carrete(){
        this.cable=100;
    }

    public int cortar(int cant){
        if(hay(cant))
           return cable-=cant;
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

        b=c.hay(50);
        System.out.println(b);
        c.cantCarrete();
        c.cortar(50);

        //c.cortar(45);
        //c.cantCarrete();
    }
}
