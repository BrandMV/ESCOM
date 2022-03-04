public class hilos implements Runnable{
    Thread printerThread;
    String string;
    int count;
    int sleepTime;

    public hilos(String s, int howMany, int sleep){
        count=howMany;
        string=s;
        sleepTime = sleep;
        printerThread=new Thread(this); //edo recien nacido
        printerThread.start(); //edo. listo
    }

    public void run(){
        while(count-->0){ //se imprime count veces
            System.out.println(string);
            try{
                Thread.sleep(sleepTime); //hacemos una pausa del hilo
            }catch(Exception e){
                return;
            }
        }
    }

    public static void main(String[] args) {
        new hilos("Ping",5,300);
        new hilos("Pong",5,500);
    }
}
