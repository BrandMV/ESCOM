/*
	nombre completo: Meza Vargas Brandon David
	Tema:  TAD banco
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/
package tadbanco;

public class mainBanco {
    public static void main(String[] args) {
        tadBanco c1,c2;

        c1 = new tadBanco("Pedro", 500.5);
        c2 = new tadBanco("Marco" , 500.5);
       

        c1.depo(500.0);
        c1.consult();
        c1.reti(400.0);

        c2.depo(700.5);
        c2.consult();
        c2.reti(350.0);

    }
}
