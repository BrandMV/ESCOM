import constants.Constants;

public class StartServers extends Thread{
    UnicastServer uServer = new UnicastServer();
    RMIServer rmiServer = new RMIServer();
    MulticastServer mServer = new MulticastServer();

    public StartServers(){
        System.out.println(Constants.SERVER_INIT_MSG);
        mServer.start();
        rmiServer.start();
        uServer.start();
    }

    public static void main(String[] args) {
        try {
            StartServers startServers = new StartServers();
            startServers.start();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
