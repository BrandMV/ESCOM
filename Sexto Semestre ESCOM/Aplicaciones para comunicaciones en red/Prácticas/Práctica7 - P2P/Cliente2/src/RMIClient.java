import constants.Constants;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;

/**
 * Invoking search method in a concurrent way through all the registered servers in our list
 */
public class RMIClient extends Thread{
    App app;
    private final Files db;

    public RMIClient(Files db, App app){
        this.app = app;
        this.db = db;
    }

    /**
     * Method that search for the spcified file
     * @param file
     */
    public void searchForFile(String file){
        int i = 0;
        try {
            List<DataFromServer> servers = db.getServers();
            if(servers.size() != 0){
                for(i = 0; i < servers.size(); i++){
                    Registry registry = LocateRegistry.getRegistry(servers.get(i).getAddress(), Constants.RMI_PORT);
                    RMISearch stub = (RMISearch) registry.lookup("Search");
                    FoundFile response = stub.search(file);
                    if(!response.getFileName().equals("unknown")){
                        app.fileFound(response.getMd5(), response.getPath(), response.getFileName(), servers.get(i).getAddress(), true);
                        db.setFoundFile(response);
                        db.setFileInServer(servers.get(i).getAddress());
                        //line to make download button appears
                        app.setDownloadVisibility(true);
                    }else{
                        //GUI LINES
                        app.fileFound("","","","", false);
                        app.setDownloadVisibility(false);
                    }
                }
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }


    public void run(){}
}
