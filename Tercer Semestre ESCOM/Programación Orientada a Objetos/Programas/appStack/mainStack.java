package appStack;


public class mainStack {
    public static void main(String[] args) {
        stack s = new stack(5);
        s.push(1);
        s.push(2);
        s.push(3);
        //s.pop();
        //s.pop();
        //p.tope=0 esta mal hacerlo
        System.out.println(""+s.top());
        while(!s.isEmpty()){ //se vacia la pila
            s.pop();
        }
        System.out.println(""+s.isEmpty());
    }
}
