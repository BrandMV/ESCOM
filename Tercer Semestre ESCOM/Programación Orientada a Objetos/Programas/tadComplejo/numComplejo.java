/*
	nombre completo: Meza Vargas Brandon David
	Tema: TAD numero complejo en java
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/


package tadComplejo;

public class numComplejo {
    Double real;
    Double imag;

    public numComplejo(Double real, Double imag){
        this.real = real;
        this.imag = imag;
        
    }

    public numComplejo sum(numComplejo c){
        return new numComplejo(real + c.real, imag + c.imag);
    }

    public numComplejo res(numComplejo c){
        return new numComplejo(real - c.real, imag - c.imag);
    }

    public numComplejo mult(numComplejo c){
        return new numComplejo((real * c.real) - (imag * c.imag), (real * c.imag) + (imag * c.real));
    }

    public numComplejo divi(numComplejo c){
        return new numComplejo(((real * c.real) + (imag * c.imag)) / ((c.real*c.real) + (c.imag*c.imag)), ( (imag*c.real) - (real*c.imag) ) / ( (c.real*c.real) + (c.imag*c.imag)));
    }

    public void mod(){
        Double modu;
        modu= Math.sqrt((real*real)+(imag*imag));
        System.out.println(modu);
    }

    public boolean esIgual(numComplejo c){
        return (c.real / real) == 1 && (c.imag / imag)==1 ;
    }

    public void imprime(){
        System.out.println(real + " + " + imag + "i");
    }
}
