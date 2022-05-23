package com.BrandMV.App.WebServer;

import com.BrandMV.App.Constants.Constants;

import java.io.*;
import java.net.Socket;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.Date;
import java.util.StringTokenizer;

public class HTTPServer extends Thread{
    protected SocketChannel socket;
    protected DataOutputStream dos;
    protected DataInputStream dis;
    protected String fileName;
    protected ByteBuffer b;

    public HTTPServer(SocketChannel socket){
        this.socket = socket;
    }

    /**
     * Method that create the connection and read the dara coming form the socket
     */
    public void connection(){
        try {
            b = ByteBuffer.allocate(Constants.INPUT_STREAM_BYTES_SIZE);
            b.clear();
            int t = socket.read(b);
            b.flip();
            String request = new String(b.array(),0,t);
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
            System.out.println(String.format(Constants.CONNECTED_CLIENT_MESSAGE,socket.socket().getInetAddress(), socket.socket().getPort()));
            System.out.println(String.format(Constants.CONNECTED_CLIENT_DATA, request));
            StringTokenizer stl = new StringTokenizer(request, "\n");
            String line = stl.nextToken();
            if(line.indexOf("?") == -1){
                if(line.toUpperCase().startsWith("HEAD")){
                    getFile(line);
                    if(fileName.compareTo("") == 0)
                        sendFileHead("index.htm", dos);
                    else sendFileHead(fileName,dos);
                }
                 else if(line.toUpperCase().startsWith("POST")){
                    String params = request.substring(request.lastIndexOf("\n"));
                    //*Getting response
                    StringBuffer response = new StringBuffer();
                    response.append("HTTP/1.0 200 OK \n");
                    String date= "Date: " + new Date()+" \n";
                    response.append(date);
                    String tipo_mime = "Content-Type: text/html \n\n";
                    response.append(tipo_mime);
                    response.append("<html><head><title>SERVIDOR WEB</title></head>\n");
                    response.append("<body bgcolor=\"#AACCFF\"><center><h1><br> Parametros obtenidos </br></h1><h3><b>\n");
                    response.append(params);
                    response.append("</b></h3>\n");
                    response.append("</center></body></html>\n\n");
                    System.out.println("Respuesta: "+response);
                    b = ByteBuffer.wrap(response.toString().getBytes());
                    socket.write(b);
                    socket.close();

                }else if(line.toUpperCase().startsWith("PUT")){
                    getFile(line);
                    while(!line.contains("Content-Type"))
                        line = stl.nextToken();
                    stl.nextToken();
                    put(stl);

                }else if(line.toUpperCase().startsWith("DELETE")){
                    getFile(line);
                    delete();
                }else{
                    getFile(line);
                    if(fileName.compareTo("") == 0)
                        sendFile("index.htm", dos);
                    else sendFile(fileName,dos);
                }
            }else if(line.toUpperCase().startsWith("GET")){
                /*
                getFile(line);
                if(fileName.compareTo("") == 0)
                    sendFile("index.htm", dos);
                else sendFile(fileName,dos);
*/
                StringTokenizer tokens = new StringTokenizer(line, "?");
                String req_a = tokens.nextToken();
                String req = tokens.nextToken();
                System.out.println("Token1: " + req_a);
                System.out.println("Token2: " + req);
                String params = req.substring(0, req.indexOf(" "))+"\n";
                System.out.println("Params: " + params);
                //*Getting response
                StringBuffer response = new StringBuffer();
                response.append("HTTP/1.0 200 OK \n");
                String date= "Date: " + new Date()+" \n";
                response.append(date);
                String tipo_mime = "Content-Type: text/html \n\n";
                response.append(tipo_mime);
                response.append("<html><head><title>SERVIDOR WEB</title></head>\n");
                response.append("<body bgcolor=\"#AACCFF\"><center><h1><br> Parametros obtenidos </br></h1><h3><b>\n");
                response.append(params);
                response.append("</b></h3>\n");
                response.append("</center></body></html>\n\n");
                System.out.println("Respuesta: "+response);
                b = ByteBuffer.wrap(response.toString().getBytes());
                socket.write(b);
                socket.close();
            }else{
                b = ByteBuffer.wrap(Constants.HTTP_NOT_IMPLEMENTED.getBytes());
                socket.write(b);
                socket.close();
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    /**
     * Method that obtains the file name and its extension
     * @param line, the line received
     */
    public void getFile(String line){
        int i, f;
        i = line.indexOf("/");
        f = line.indexOf(" ",i);
        fileName = line.substring(i+1,f);

    }
    /**
     * Method that send the file when is HEAD request
     * @param arg The file name
     * @param dos1 The data OutputStream required to write
     */
    public void sendFileHead(String arg, DataOutputStream dos1){
        try{

            String extension = "";
            int i = arg.lastIndexOf('.');
            if(i > 0) extension = arg.substring(i+1);

            System.out.println("Etension "+ extension);
            DataInputStream dis2 = new DataInputStream(new FileInputStream(arg));
            File ff = new File(arg);
            long fileSize = ff.length();
            /***********************************************/
            String sb = "";
            sb = sb+"HTTP/1.0 200 ok\n";
            sb = sb +"Server: BrandonMV Server/1.0 \n";
            sb = sb +"Date: " + new Date()+" \n";
            switch (extension){
                case "htm":
                case "html":
                    sb = sb +"Content-Type: text/html \n";
                    break;
                case "jpg":
                case "jpeg":
                    sb = sb + "Content-Type: image/jpeg \n";
                    break;
                case "pdf":
                    sb = sb +"Content-Type: application/pdf \n";
                    break;
            }
            //sb = sb +"Content-Type: text/html \n";
            sb = sb +"Content-Length: "+fileSize+" \n";
            sb = sb +"\n";
            b = ByteBuffer.wrap(sb.getBytes());
            socket.write(b);
            /***********************************************/
            dis2.close();
            socket.close();
        }catch (IOException e){
            System.err.println(e.getMessage());
        }
    }
    /**
     * Method that send the file
     * @param arg The file name
     * @param dos1 The data OutputStream required to write
     */
    public void sendFile(String arg, DataOutputStream dos1){
        try{
            String extension = "";
            int i = arg.lastIndexOf('.');
            if(i > 0) extension = arg.substring(i+1);

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
            switch (extension){
                case "htm":
                case "html":
                    sb = sb +"Content-Type: text/html \n";
                    break;
                case "jpg":
                case "jpeg":
                    sb = sb + "Content-Type: image/jpeg \n";
                    break;
                case "pdf":
                    sb = sb +"Content-Type: application/pdf \n";
                    break;
            }
            //sb = sb +"Content-Type: text/html \n";
            sb = sb +"Content-Length: "+fileSize+" \n";
            sb = sb +"\n";
            b = ByteBuffer.wrap(sb.getBytes());
            socket.write(b);
            /***********************************************/
            while(cont < fileSize){
                x = dis2.read(buf);
                b = ByteBuffer.wrap(buf, 0 , x);
                socket.write(b);
                cont+=x;
            }
            dis2.close();
            socket.close();
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
                response("200", "OK", "Archivo eliminado");
            }else{
                response("403", "Forbidden", "403 FORBIDDEN");
            }
        }else{
            response("404", "Not Found", "404 Not Found");
        }
    }

    /**
     * Method that updates or creates a file
     * @param stl   The file content
     * @throws IOException  Excpetion thrown
     */
    private void put(StringTokenizer stl) throws IOException{
        FileWriter fw;
        File f = new File(fileName); //* File to create or update
        File f2 = new File(fileName); //* File updated
        //*If the file exists and is writable means that the file will be updated
        if(f.exists()){
            if(f.canWrite()){
                f.delete();
                f2.createNewFile();
                fw = new FileWriter(fileName);
                while(stl.hasMoreTokens())
                    fw.write(stl.nextToken());
                fw.close();
                response("200", "OK", "Archivo actualizado");
            }else response("403", "Forbidden", "403 Forbidden");/** Sin permiso para escribir*/
        }else{
            //* If file does not exist we have to create it
            f.createNewFile();
            response("201", "Created", "Archivo creado");
            fw = new FileWriter(fileName);
            while(stl.hasMoreTokens())
                fw.write(stl.nextToken());
            fw.close();
        }
    }

    /**
     * Method that set the html response
     * @param statusCode The status code
     * @param meaning The status code meaning
     * @param msg   The message that will be print
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
        b = ByteBuffer.wrap(response.toString().getBytes());
        socket.write(b);
        socket.close();
    }

}
