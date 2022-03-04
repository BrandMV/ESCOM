/*
	nombre completo: Meza Vargas Brandon David
	Tema: TAD numero complejo en java
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/

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

    public Double mod(){ 
        return Math.sqrt((real*real)+(imag*imag));
    }

    public boolean esIgual(numComplejo c){
        return (c.real / real) == 1 && (c.imag / imag)==1 ;
    }

    public void imprime(){
        System.out.println(real + " + " + imag + "i");
    }

    public static void main(String[] args) {
        numComplejo c1,c2,c3,c4,c5,c6;
        boolean r;
        Double mod;

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
        mod= c1.mod();
        System.out.println(mod);
        mod =c2.mod();
        System.out.println(mod);
        
    }
}


