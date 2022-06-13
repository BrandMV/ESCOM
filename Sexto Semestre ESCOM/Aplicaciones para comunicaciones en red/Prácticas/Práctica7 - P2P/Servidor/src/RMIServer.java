import constants.Constants;

import java.io.File;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Will work as a search service returning the found file name and its MD5
 */
public class RMIServer extends Thread implements RMISearch {
    File directory = new File(Constants.FILES_PATH);

    public void run(){
        try {
            java.rmi.registry.LocateRegistry.createRegistry(Constants.RMI_PORT);
            RMIServer obj = new RMIServer();
            RMISearch stub = (RMISearch) UnicastRemoteObject.exportObject(obj, Constants.RMI_PORT);
            Registry registry = LocateRegistry.getRegistry(Constants.RMI_PORT);
            registry.bind("Search", stub);
        }catch (Exception e){
            e.printStackTrace();
        }

    }

    @Override
    public FoundFile search(String file) throws RemoteException {
        return searchFile(file, directory);
    }

    public FoundFile searchFile(String filename, File dir){
        FoundFile result = new FoundFile();
        result.setFileName("unknown");

        File[] files = dir.listFiles();
        for(File file : files)
            if(file.isFile())
                if(file.getName().equals(filename)){
                    result.setFileName(file.getName());
                    result.setPath(file.getAbsolutePath());
                    result.setMd5(getMD5(file.getAbsolutePath()));
                }

        return result;
    }

    public String getMD5(String path){
        try {
            MD5Checksum md5 = new MD5Checksum();
            return md5.getMD5Checksum(path);
        }catch (Exception e){
            Logger.getLogger(RMIServer.class.getName()).log(Level.SEVERE, null, e);
        }
        return null;
    }

    public static void main(String[] args) {
        try {
            RMIServer rmiServer = new RMIServer();
            rmiServer.start();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
