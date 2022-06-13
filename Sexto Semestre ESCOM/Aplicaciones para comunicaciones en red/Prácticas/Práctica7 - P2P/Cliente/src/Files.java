
import java.util.ArrayList;
import java.util.List;

/**
 * Class that will simulate a database
 */
public class Files {
    private String fileInServer = new String();
    private List<DataFromServer> servers = new ArrayList<>();
    private FoundFile foundFile = new FoundFile();

    public String getFileInServer() {
        return fileInServer;
    }

    public void setFileInServer(String fileInServer) {
        this.fileInServer = fileInServer;
    }

    public List<DataFromServer> getServers() {
        return servers;
    }

    public void setServers(List<DataFromServer> servers) {
        this.servers = servers;
    }

    public FoundFile getFoundFile() {
        return foundFile;
    }

    public void setFoundFile(FoundFile foundFile) {
        this.foundFile = foundFile;
    }
    public void addServer(DataFromServer dfs){
        servers.add(dfs);
    }
}
