package com.brandmv.app;

import java.io.*;
import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FileDownloader extends Thread{
    URL link;
    String path;
    private final ExecutorService pool;

    public FileDownloader(String link, String path, int op){
        pool = Executors.newFixedThreadPool(Constants.THREADS);
        try {
            this.link = new URL(link);
            this.path = path;
            if(op == 1)
                getFiles();
            else
                downloadFiles(new File(path+ "/" + getFileName(link)));
        }catch (Exception e){
            e.printStackTrace();
            pool.shutdown();
        }
        pool.shutdown();
    }


    public FileDownloader(String link, String path, final ExecutorService pool, int op){
        this.pool = pool;
        try {
            this.link = new URL(link);
            this.path = path;
            if(op == 1)
                getFiles();
            else
                downloadFiles(new File(path+"/index.html"));
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    /**
     * Method that check if the file is a directory or a single file
     */
    public void getFiles(){
        if(link.getFile().indexOf(".") == -1)
            isDir();
        else
            downloadFiles(new File(path + getFileName(link.getFile())));
    }

    /**
     * Method that obtains the file name
     * @param file The file which name will be obtained
     * @return The file nime
     */
    public String getFileName(String file){
        String [] x = file.split("/");
        return x[x.length-1];
    }

    /**
     * Method that establish if a file is a directory, if so, a new thread is created to download the files into the directory
     */
    public void isDir(){
        File file = new File(path+getFileName(link.getFile()));

        if(file.mkdir()){
            path = file.getAbsolutePath()+"\\";
            try {
                DataInputStream dis = new DataInputStream(link.openStream());
                byte [] b = new byte[Constants.BUFFER_SIZE];
                int l = dis.read(b);
                String s = "";
                /** Downloading data*/
                while(l != -1){
                    s += new String(b, 0, l);
                    l = dis.read(b);
                }
                int i = s.indexOf("PARENTDIR");
                if(i == -1){
                    System.out.println(String.format(Constants.FILE_ERROR, link.getFile()));
                    pool.execute(new FileDownloader(link.toString(), path, pool, 0));
                    return;
                }
                i = s.indexOf("href", i);
                pool.execute(new FileDownloader(link.toString(), path, pool, 0));
                while((i = s.indexOf("href", i+1)) != -1){
                    String nextFile = s.substring(i+6, s.indexOf("\"", i+6));
                    pool.execute(new FileDownloader(link.toString()+nextFile, path, pool, 1));
                }
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }

    /**
     * Method that download the files that are in the url the user wrote
     * @param file the file is being downloaded
     */
    public void downloadFiles(File file){
        try {
            System.out.println(String.format(Constants.DOWNLOAD_FILE_MESSAGE, file.getName()));
            DataOutputStream dos = new DataOutputStream(new FileOutputStream(file));
            DataInputStream dis = new DataInputStream(link.openStream());

            byte[] b = new byte[Constants.BUFFER_SIZE];
            int l = dis.read(b);
            /** Downloading data*/
            while(l != -1){
                dos.write(b, 0, l);
                l = dis.read(b);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }


}
