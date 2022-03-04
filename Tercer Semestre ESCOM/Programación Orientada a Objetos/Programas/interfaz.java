public class interfaz {
    
}

interface Coprable{
    void comer();
}

/*class Pelotero implements Coprable{
    public void comer(){
        System.out.println("YUMMY YUMMY");
    }
}*/

interface Limpiable{
    void comer();
}

class Pelotero implements Limpiable{
    public void comer(){
        System.out.println("YUMMY YUMMY");
    }
}

interface Morturia{
    void comer();
}

class Larva implements Morturia{
    public void comer(){
        System.out.println("YUMMY YUMMY");
    }
}