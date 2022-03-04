package appStack;

//  Todos los elementos de una interfaz deben ser publicos 
public class stack {
    private int eltos[]; //en c seria int *eltos; al ponerlos privados los encapsulamos, al encapsular protegemos controlando que entra y que sale
    private int tope;
    public stack(int n){
        tope=0;
        eltos = new int[n]; //en c equivale a eltos=(int *)malloc(sizeof(int)*n);
    }
    public void push(int dato){ //los metodos deben ser publicos, el usuario debe de conocerlos
        eltos[tope]=dato;
        tope+=1;
    }
    public int pop(){
        tope-=1;
        return eltos[tope];
    }
    public int top(){
        return eltos[tope-1];
    }
    public boolean isEmpty(){
        return tope ==0;
    }

}
