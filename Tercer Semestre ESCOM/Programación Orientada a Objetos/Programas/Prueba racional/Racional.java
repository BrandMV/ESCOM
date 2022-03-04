
/*
	nombre completo: Meza Vargas Brandon David
	Tema: suma y resta de racionales en java
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/

public class Racional{
    int num, den;
    public Racional(int num, int den){
        this.num= num;
        this.den= den;
    }

    public Racional mult (Racional r){
        return new Racional(num * r.num, den * r.den);
    }

    public Racional divi(Racional r){
        return new Racional(num * r.den, den * r.num);
    }

    public Racional sum(Racional r){
        return new Racional((num * r.den + den * r.num), den * r.den);
    }

    public Racional res(Racional r){
        return new Racional((num * r.den - den * r.num), den * r.den);
    }

    public boolean comparaIgual(Racional r){
        return num * r.den == den * r.num;

    }

    void imprime(){
        System.out.println(this.num + " / " + this.den);
    }

        public static void main(String[] args) {
            Racional r1, r2, r3, r4,r5,r6;
            boolean a;

            r1 = new Racional(7,4);
            r2 = new Racional(7,4);

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



