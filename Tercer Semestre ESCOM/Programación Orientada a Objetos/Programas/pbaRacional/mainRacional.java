/*
	nombre completo: Meza Vargas Brandon David
	Tema:  TAD racional
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/

package pbaRacional;

public class mainRacional{
public static void main(String[] args) {
    Racional r1, r2, r3, r4,r5,r6;
    boolean a;

    r1 = new Racional(7,2);
    r2 = new Racional(7,2);

    System.out.println("Multiplicacion: ");
    r3 = r1.mult(r2);
    r3.imprime();

    System.out.println("Division: ");
    r4 = r1.divi(r2);
    r4.imprime();

    System.out.println("Suma: ");
    r5 = r1.sum(r2);
    r5.imprime();

    System.out.println("Resta: ");
    r6 = r1.res(r2);
    r6.imprime();

    System.out.println("¿Es igual?: ");
    a=r1.comparaIgual(r2);
    System.out.println(a);

}
}