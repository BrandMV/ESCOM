/*
	nombre completo: Meza Vargas Brandon David
	Tema: TAD numero complejo en java
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/

package tadComplejo;

public class mainComplejo {
    public static void main(String[] args) {
        numComplejo c1,c2,c3,c4,c5,c6;
        boolean r;

        c1= new numComplejo(14.0, 2.0);
        c2= new numComplejo(14.0, 2.0);

        System.out.println("¿Es igual?: ");
        r=c1.esIgual(c2);
        System.out.println(r);

        System.out.println("Suma: ");
        c3 = c1.sum(c2);
        c3.imprime();

        System.out.println("Resta: ");
        c4 = c1.res(c2);
        c4.imprime();
    
        System.out.println("Multiplicacion: ");
        c5=c1.mult(c2);
        c5.imprime();

        System.out.println("Division: ");
        c6=c1.divi(c2);
        c6.imprime();

        System.out.println("Modulos: ");
        c1.mod();
        c2.mod();

        
    }
}
