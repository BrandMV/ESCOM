package Server;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;
import java.util.StringTokenizer;

/**
 *
 * @author huert
 */
public class HTTPServer extends Thread{
    protected Socket socket;
    protected PrintWriter pw;
    protected BufferedOutputStream bos;
    protected BufferedReader br;
    private DataOutputStream dos;
    private DataInputStream dis;
    protected String fileName;
                        
    public HTTPServer(Socket socket) {
        this.socket = socket;
    }
	
    public void run() {
        try {
            dos = new DataOutputStream(socket.getOutputStream());
            dis = new DataInputStream(socket.getInputStream());
            byte[] b = new byte[1024];
            int t = dis.read(b);
            String request = new String(b,0,t);
            System.out.println("t: "+t);
            if(request == null) {
                StringBuilder sb = new StringBuilder();
                sb.append("<html><head><title>Servidor WEB\n");
                sb.append("</title><body bgcolor=\"#AACCFF\"<br>Linea Vacia</br>\n");
                sb.append("</body></html>\n");
                dos.write(sb.toString().getBytes());
                dos.flush();
                socket.close();
                return;
            }
            System.out.println("\nClient connected from: "+socket.getInetAddress());
            System.out.println("At port: "+socket.getPort());
            System.out.println("Request:\n"+request+"\r\n\r\n");
            StringTokenizer st1= new StringTokenizer(request,"\n");
            String line = st1.nextToken();
            if(line.indexOf("?") == -1) {
                if(line.toUpperCase().startsWith("POST")){
                    String lastToken = request.substring(request.lastIndexOf("\n"));
                    System.out.println(lastToken);
                    paramsResponse(lastToken);
                } else if (line.toUpperCase().startsWith("PUT")) {
                    getFileName(line);
                    while(!line.contains("Content-Type")) line = st1.nextToken();
                    st1.nextToken();
                    put(st1);
                } else if (line.toUpperCase().startsWith("DELETE")) {
                    getFileName(line);
                    delete();
                } else { //HEAD OR GET WITHPUT PARAMS
                    getFileName(line);
                    boolean get = (line.toUpperCase().startsWith("GET"));
                    if(fileName.compareTo("") == 0)
                        sendFile("index.htm",dos, get);
                    else
                        sendFile(fileName,dos, get);
                }
            } else if(line.toUpperCase().startsWith("GET")) { //GET WITH PARAMS
                StringTokenizer tokens=new StringTokenizer(line,"?");
                String req_a = tokens.nextToken();
                System.out.println("Token1: "+req_a);
                String req = tokens.nextToken();
                System.out.println("Token2: "+req);
                String params = req.substring(0, req.indexOf(" "))+"\n";
                paramsResponse(params);
            } else
                sendStatus(501, "Not Implemented");
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
    
    private void paramsResponse(String params) throws IOException{
        System.out.println("Params: "+params);
        StringBuffer response= new StringBuffer();
        response.append("HTTP/1.0 200 Okay \n");
        response.append("Date: ").append(new Date()).append(" \n");
        String mimeType = "Content-Type: text/html \n\n";
        response.append(mimeType);
        response.append("<html><head><title>SERVIDOR WEB</title></head>\n");
        response.append("<body bgcolor=\"#AACCFF\"><center><h1><br>Parametros Obtenidos..</br></h1><h3><b>\n");
        response.append(params);
        response.append("</b></h3>\n</center></body></html>\n\n");
        System.out.println("Response: "+response);
        dos.write(response.toString().getBytes());
        dos.flush();
        dos.close();
        socket.close();
    }
    
    private void delete() throws IOException{
        System.out.println("DELETE");
        File file = new File(fileName);
        if(file.exists())
            if(Files.isWritable(Paths.get(fileName))){
                file.delete();
                System.out.println(fileName + " deleted");
                htmlResponse(200, "OK", "File deleted");
            } else {
                System.out.println(fileName + " not deleted");
                htmlResponse(200, "OK", "File not deleted");
            }
        else
            htmlResponse(404, "Not found", "404 Not Found");
    }
    
    private void put(StringTokenizer content) throws IOException{
        System.out.println("PUT");
        File file = new File(fileName);
        File nfile = new File(fileName);
        if(file.exists()){
            if(Files.isWritable(Paths.get(fileName))){
                file.delete();
                nfile.createNewFile();
                FileWriter myWriter = new FileWriter(fileName);
                while(content.hasMoreTokens()) myWriter.write(content.nextToken());
                myWriter.close();
                System.out.println(fileName + " updated");
                htmlResponse(200, "OK", "File updated");
            } else {
                System.out.println(fileName + " not updated");
                htmlResponse(200, "OK", "You don't have permission to modify this file.");
            }
        } else {
            file.createNewFile();
            System.out.println(fileName + " created");
            htmlResponse(201, "CREATED", "File created");
            FileWriter myWriter = new FileWriter(fileName);
            while(content.hasMoreTokens()) myWriter.write(content.nextToken());
            myWriter.close();
        }
    }
    
    private void htmlResponse(int code, String status, String msg) throws IOException{
        StringBuilder sb = new StringBuilder();
        sb.append("HTTP/1.0 "+code+" "+status+"\r\n");
        sb.append("Date: ").append(new Date()).append(" \n");
        String mimeType = "Content-Type: text/html \n\n";
        sb.append(mimeType);
        sb.append("<html><head><title>Servidor WEB\n");
        sb.append("</title><body bgcolor=\"#AACCFF\"<br>"+msg+"</br>\n");
        sb.append("</body></html>\n");
        dos.write(sb.toString().getBytes());
        dos.flush();
        socket.close();
    }

    private void getFileName(String line) {
        int i, f;
        i=line.indexOf("/");
        f=line.indexOf(" ",i);
        fileName=line.substring(i+1,f);
    }
    
    private void sendStatus(int code, String msg) throws IOException{
        String response = "HTTP/1.0 "+code+" "+msg+"\r\n";
        System.out.println(response);
        dos.write(response.getBytes());
        dos.flush();
        dos.close();
        socket.close();
    }

    private void sendFile(String filePath, DataOutputStream dos1, boolean get)
        throws IOException{
        int x = 0;
        DataInputStream dis2 = new DataInputStream(new FileInputStream(filePath));
        byte[] buf=new byte[1024];
        File ff = new File(filePath);			
        long tam_archivo=ff.length(),cont=0;
        StringBuffer sb = new StringBuffer();
        sb.append("HTTP/1.0 200 ok\r\n").append("Server: HTTPServer/1.0 \r\n");
        sb.append("Date: ").append(new Date()).append(" \r\n");
        sb.append("Content-Type: text/html \r\n");
        sb.append("Content-Length: ").append(tam_archivo).append(" \r\n\r\n");
        System.out.println(sb);
        dos1.write(sb.toString().getBytes());
        dos1.flush();
        if(get)
            while(cont<tam_archivo) {
                x = dis2.read(buf);
                dos1.write(buf,0,x);
                cont += x;
                dos1.flush();
            }
        dis2.close();
        dos1.close();
    }
}
