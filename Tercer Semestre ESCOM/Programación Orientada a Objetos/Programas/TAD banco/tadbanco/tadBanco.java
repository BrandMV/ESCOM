/*
	nombre completo: Meza Vargas Brandon David
	Tema:  TAD banco
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/
package tadbanco;


public class tadBanco {
    String cuentahabiente;
    Double saldo;

    public tadBanco(String cuentahabiente, Double saldo){
        this.cuentahabiente = cuentahabiente;
        this.saldo = saldo;
    }

    public void depo(Double cantidad){
        saldo=saldo+cantidad;
    }

    public void reti(Double cantidad){
        if(cantidad>saldo)
            System.out.println("No puedes retirar mas de "+ saldo );
        else   
            saldo = saldo - cantidad;
    }

    public void consult(){
        System.out.println("Tu " + cuentahabiente + " tienes " + saldo +" pesos");
    }
}
