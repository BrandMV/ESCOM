
import java.io.Serializable;

/**
 * Class that has the server info
 */
public class DataFromServer implements Serializable {
    private String address;
    private int temp;
    private int port;

    public DataFromServer(String address, int temp, int port) {
        this.address = address;
        this.temp = temp;
        this.port = port;
    }

    public DataFromServer(){}

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getTemp() {
        return temp;
    }

    public void setTemp(int temp) {
        this.temp = temp;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }
}
