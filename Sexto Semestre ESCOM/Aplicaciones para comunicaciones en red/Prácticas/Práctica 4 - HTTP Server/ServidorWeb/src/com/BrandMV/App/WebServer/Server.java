package com.BrandMV.App.WebServer;

import com.BrandMV.App.Constants.Constants;

import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.StringTokenizer;

public class Server extends Thread{
    protected Socket socket;
    protected PrintWriter pw;
    protected BufferedOutputStream bos;
    protected BufferedReader br;
    protected DataOutputStream dos;
    protected DataInputStream dis;
    protected String fileName;

    public Server(Socket socket){
        this.socket = socket;
    }

    public void run(){
        try {
            dos = new DataOutputStream(socket.getOutputStream());
            dis = new DataInputStream(socket.getInputStream());
            byte[] b = new byte[Constants.INPUT_STREAM_BYTES_SIZE];
            int t = dis.read(b);
            String request = new String(b,0,t);
            System.out.println("t: " + t);

            if(request == null){
                StringBuilder sb = new StringBuilder();
                sb.append("<html><head><title>Servidor WEB\n");
                sb.append("</title><body bgcolor=\"#AACCFF\"<br>Linea Vacia</br>\n");
                sb.append("</body></html>\n");
                dos.write(sb.toString().getBytes());
                dos.flush();
                socket.close();
                return;
            }

            System.out.println(String.format(Constants.CONNECTED_CLIENT_MESSAGE,socket.getInetAddress(), socket.getPort()));
            System.out.println(String.format(Constants.CONNECTED_CLIENT_DATA, request));

            StringTokenizer stl = new StringTokenizer(request, "\n");
            String line = stl.nextToken();

            if(line.indexOf("?") == -1){
                if(line.toUpperCase().startsWith("HEAD")){
                    getFile(line);
                    if(fileName.compareTo("") == 0)
                        sendFile("index.htm", dos);
                    else sendFile(fileName,dos);

                }else if(line.toUpperCase().startsWith("POST")){

                }else if(line.toUpperCase().startsWith("PUT")){
                    getFile(line);


                }else if(line.toUpperCase().startsWith("DELETE")){
                    getFile(line);
                    delete();
                }
            }else if(line.toUpperCase().startsWith("GET")){
                StringTokenizer tokens = new StringTokenizer(line, "?");
                String req_a = tokens.nextToken();
                String req = tokens.nextToken();
                System.out.println("Token1: " + req_a);
                System.out.println("Token2: " + req);
                String params = req.substring(0, req.indexOf(" "))+"\n";
                System.out.println("Params: " + params);
                //*Getting response
                response("200", "OK", "Parametros Obtenidos");
            }else{
                dos.write(Constants.HTTP_NOT_IMPLEMENTED.getBytes());
                dos.flush();
                dos.close();
                socket.close();
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    /**
     * Method that obtains the file name
     * @param line, the line recieved
     */
    public void getFile(String line){
        int i, f;
        i = line.indexOf("/");
        f = line.indexOf(" ",i);
        fileName = line.substring(i+1,f);
    }

    /**
     * Method that send the file
     * @param arg The file name
     * @param dos1 The data OutputStream required to write
     */
    public void sendFile(String arg, DataOutputStream dos1){
        try{
            int readB = 0;
            DataInputStream dis2 = new DataInputStream(new FileInputStream(arg));
            byte[] buf = new byte[Constants.INPUT_STREAM_BYTES_SIZE];
            int x = 0;
            File ff = new File(arg);
            long fileSize = ff.length(), cont = 0;
            /***********************************************/
            String sb = "";
            sb = sb+"HTTP/1.0 200 ok\n";
            sb = sb +"Server: BrandonMV Server/1.0 \n";
            sb = sb +"Date: " + new Date()+" \n";
            sb = sb +"Content-Type: text/html \n";
            sb = sb +"Content-Length: "+fileSize+" \n";
            sb = sb +"\n";
            dos1.write(sb.getBytes());
            dos1.flush();
            /***********************************************/

            while(cont < fileSize){
                x = dis2.read(buf);
                dos1.write(buf, 0, x);
                cont+=x;
                dos1.flush();
            }
            dis2.close();
            dos1.close();

        }catch (IOException e){
            System.err.println(e.getMessage());
        }
    }

    /**
     * The delete HTTP method, deletes the indicated file
     * @throws IOException
     */
    private void delete() throws IOException{
        File f = new File(fileName);
        if(f.exists()){
            if(f.canWrite()){
                f.delete();
                //*Getting response
                response("200", "OK", "File deleted");
            }else{
                response("403", "Forbidden", "403 FORBIDDEN");
            }
        }else{
            response("404", "Not Found", "404 Not Found");
        }

    }

    /**
     * Method that set the html response
     * @param statusCode The status code
     * @param meaning The status code meaning
     * @param msg   The message that will be print
     * @throws IOException
     */
    private void response(String statusCode, String meaning, String msg) throws IOException{
        StringBuffer response = new StringBuffer();
        response.append("HTTP/1.0 " + statusCode + meaning + " \n");
        String date= "Date: " + new Date()+" \n";
        response.append(date);
        String tipo_mime = "Content-Type: text/html \n\n";
        response.append(tipo_mime);
        response.append("<html><head><title>SERVIDOR WEB</title></head>\n");
        response.append("<body bgcolor=\"#AACCFF\"><center><h1><br>" + msg + "</br></h1><h3><b>\n");
        response.append("</b></h3>\n");
        response.append("</center></body></html>\n\n");
        System.out.println("Respuesta: "+response);
        dos.write(response.toString().getBytes());
        dos.flush();
        dos.close();
        socket.close();
    }

}
