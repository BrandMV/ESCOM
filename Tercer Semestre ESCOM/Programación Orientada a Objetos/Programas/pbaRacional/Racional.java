/*
	nombre completo: Meza Vargas Brandon David
	Tema:  TAD racional
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/

package pbaRacional;

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
}
