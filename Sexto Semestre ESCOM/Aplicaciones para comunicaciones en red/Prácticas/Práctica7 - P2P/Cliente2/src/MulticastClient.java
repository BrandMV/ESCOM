import constants.Constants;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.List;

/**
 * We join to the multicast group reading all datagrams
 * generating a list of servers that is updated every second
 */
public class MulticastClient extends Thread{
    private List<DataFromServer> servers = new ArrayList<>();
    private InetAddress group = null;
    private final Files db;

    public MulticastClient(Files db){
        this.db = db;
        try {
            group = InetAddress.getByName(Constants.MULTICAST_ADDRESS);
        }catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void run(){
        try {
            MulticastSocket socket = new MulticastSocket(Constants.MULTICAST_PORT);
            socket.joinGroup(group);
            String msg = "";
            for(;;){
                byte []buffer = new byte[Constants.BUFFER_SIZE];
                DatagramPacket recv = new DatagramPacket(buffer, buffer.length);
                socket.receive(recv);
                byte []data = recv.getData();
                msg = new String(data);
                msg = msg.trim();

                /**Verifying if server is already saved*/
                DataFromServer curServer = new DataFromServer(recv.getAddress().toString().substring(1), 6, recv.getPort());
                /**Adding server*/
                servers = db.getServers();
                int pos = isInList(servers, curServer);
                if(pos == -1){
                    db.addServer(curServer);

                }else{
                    servers.get(pos).setTemp(6);
                    db.setServers(servers);
                }
            }
        }catch (IOException e){
            e.printStackTrace();
            System.exit(2);
        }
    }

    public int isInList(List<DataFromServer>list, DataFromServer dfs){
        int i = 0;
        for(i = 0; i < list.size(); i++){
            if(list.get(i).getAddress().equals(dfs.getAddress())){
                return i;
            }
        }
        return -1;
    }


}
