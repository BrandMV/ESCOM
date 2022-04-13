import java.net.*;
import java.io.*;
import java.util.*;

public class ServidorWeb1
{
	public static final int PUERTO=8000;
	ServerSocket ss;
		
		class Manejador extends Thread
		{
			protected Socket socket;
			protected PrintWriter pw;
			protected BufferedOutputStream bos;
			protected BufferedReader br;
                        DataOutputStream dos;
                        DataInputStream dis;
			protected String FileName;
			
			public Manejador(Socket _socket) throws Exception
			{
				this.socket=_socket;
			}
			
			public void run()
			{
				try{
					//br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
					//bos=new BufferedOutputStream(socket.getOutputStream());
					//pw=new PrintWriter(new OutputStreamWriter(bos));
                                        dos = new DataOutputStream(socket.getOutputStream());
                                        dis = new DataInputStream(socket.getInputStream());
					//String line=br.readLine();
                                        byte[] b = new byte[1024];
                                        int t = dis.read(b);
                                        String peticion = new String(b,0,t);
					System.out.println("t: "+t);
					if(peticion==null)
					{
						StringBuffer sb = new StringBuffer();
                                                sb.append("<html><head><title>Servidor WEB\n");
						sb.append("</title><body bgcolor=\"#AACCFF\"<br>Linea Vacia</br>\n");
						sb.append("</body></html>\n");
                                                dos.write(sb.toString().getBytes());
                                                dos.flush();
						socket.close();
						return;
					}
					System.out.println("\nCliente Conectado desde: "+socket.getInetAddress());
					System.out.println("Por el puerto: "+socket.getPort());
					System.out.println("Datos: "+peticion+"\r\n\r\n");
                                        
					StringTokenizer st1= new StringTokenizer(peticion,"\n");
                                        String line = st1.nextToken();
					if(line.indexOf("?")==-1)
					{
						getArch(line);
						if(FileName.compareTo("")==0)
						{
							SendA("index.htm",dos);
						}
						else
						{
							SendA(FileName,dos);
						}
						//System.out.println(FileName);
						
						
					}else if(line.toUpperCase().startsWith("GET"))
					{
						StringTokenizer tokens=new StringTokenizer(line,"?");
						String req_a=tokens.nextToken();
						String req=tokens.nextToken();
						System.out.println("Token1: "+req_a);
						System.out.println("Token2: "+req);
                                                String parametros = req.substring(0, req.indexOf(" "))+"\n";
                                                System.out.println("parametros: "+parametros);
                                                StringBuffer respuesta= new StringBuffer();
                                                
                                                respuesta.append("HTTP/1.0 200 Okay \n");
                                                String fecha= "Date: " + new Date()+" \n";
                                                respuesta.append(fecha);
                                                String tipo_mime = "Content-Type: text/html \n\n";
                                                respuesta.append(tipo_mime);
                                                respuesta.append("<html><head><title>SERVIDOR WEB</title></head>\n");
                                                respuesta.append("<body bgcolor=\"#AACCFF\"><center><h1><br>Parametros Obtenidos..</br></h1><h3><b>\n");
                                                respuesta.append(parametros);
                                                respuesta.append("</b></h3>\n");
                                                respuesta.append("</center></body></html>\n\n");
                                                System.out.println("Respuesta: "+respuesta);
                                                dos.write(respuesta.toString().getBytes());
                                                dos.flush();
                                                dos.close();
                                                socket.close();
					}
					else
					{
						dos.write("HTTP/1.0 501 Not Implemented\r\n".getBytes());
                                                dos.flush();
                                                dos.close();
                                                socket.close();
						//pw.println();
					}
					//dos.flush();
					//bos.flush();
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
//				try{
//                                    dos.close();
//                                    socket.close();
//				}
//				catch(Exception e)
//				{
//					e.printStackTrace();
//				}
			}//run
			
			public void getArch(String line)
			{
				int i;
				int f;
				if(line.toUpperCase().startsWith("GET"))
				{
					i=line.indexOf("/");
					f=line.indexOf(" ",i);
					FileName=line.substring(i+1,f);
				}
			}
			public void SendA(String fileName,Socket sc,DataOutputStream dos)
			{
				//System.out.println(fileName);
				int fSize = 0;
				byte[] buffer = new byte[4096];
				try{
					//DataOutputStream out =new DataOutputStream(sc.getOutputStream());
					
					//sendHeader();
                                        DataInputStream dis1 = new DataInputStream(new FileInputStream(fileName));
					//FileInputStream f = new FileInputStream(fileName);
					int x = 0;
                                        File ff = new File("fileName");
                                        long tam, cont=0;
                                        tam = ff.length();
					while(cont<tam)
					{
                                            x = dis1.read(buffer);
                                            dos.write(buffer,0,x);
                                            cont =cont+x;
                                            dos.flush();
					}
					//out.flush();
					dis.close();
                                        dos.close();
				}catch(FileNotFoundException e){
					//msg.printErr("Transaction::sendResponse():1", "El archivo no existe: " + fileName);
				}catch(IOException e){
		//			System.out.println(e.getMessage());
					//msg.printErr("Transaction::sendResponse():2", "Error en la lectura del archivo: " + fileName);
				}
				
			}
			public void SendA(String arg, DataOutputStream dos1) 
			{
                         try{
			     int b_leidos=0;
                             DataInputStream dis2 = new DataInputStream(new FileInputStream(arg));
			    // BufferedInputStream bis2=new BufferedInputStream(new FileInputStream(arg));
                     byte[] buf=new byte[1024];
                     int x=0;
                     File ff = new File(arg);			
                     long tam_archivo=ff.length(),cont=0;
		     /***********************************************/
				String sb = "";
				sb = sb+"HTTP/1.0 200 ok\n";
			        sb = sb +"Server: Axel Server/1.0 \n";
				sb = sb +"Date: " + new Date()+" \n";
				sb = sb +"Content-Type: text/html \n";
				sb = sb +"Content-Length: "+tam_archivo+" \n";
				sb = sb +"\n";
				dos1.write(sb.getBytes());
				dos1.flush();
		     /***********************************************/
			
                     while(cont<tam_archivo)
                     {
                         x = dis2.read(buf);
                         dos1.write(buf,0,x);
                         cont=cont+x;
                         dos1.flush();
                        
                        
                     }
                     //bos.flush();
                     dis2.close();
                     dos1.close();
                     
                     
				}
				catch(Exception e)
				{
					System.out.println(e.getMessage());
				}
				
			}
		}
		public ServidorWeb1() throws Exception
		{
			System.out.println("Iniciando Servidor.......");
			this.ss=new ServerSocket(PUERTO);
			System.out.println("Servidor iniciado:---OK");
			System.out.println("Esperando por Cliente....");
			for(;;)
			{
				Socket accept=ss.accept();
				new Manejador(accept).start();
			}
		}
		
		
		
		public static void main(String[] args) throws Exception{
			ServidorWeb1 sWEB=new ServidorWeb1();
		}
	
}