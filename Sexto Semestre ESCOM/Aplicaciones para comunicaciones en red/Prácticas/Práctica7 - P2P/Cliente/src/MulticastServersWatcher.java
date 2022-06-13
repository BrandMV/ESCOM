
import java.util.List;

public class MulticastServersWatcher extends Thread{
    private final Files db;

    public MulticastServersWatcher(Files db){
        this.db = db;
    }

    /**
     * We check for the timer initialized in 6 seconds waiting for a datagram
     * if a datagram is not captures we delete the server from the list
     */
    public void run(){
        int i = 0;
        for(;;){
            try {
                List<DataFromServer> servers = db.getServers();
                if(servers.size() != 0){

                    for (i = 0; i < servers.size(); i++){
                        /**Removing server if is not reported*/
                        if(servers.get(i).getTemp() == 0)
                            servers.remove(i);
                        else
                            servers.get(i).setTemp(servers.get(i).getTemp()-1);
                    }
                }
                Thread.sleep(1000);
            }catch (InterruptedException e){
                Thread.currentThread().interrupt();
            }
        }
    }
}
