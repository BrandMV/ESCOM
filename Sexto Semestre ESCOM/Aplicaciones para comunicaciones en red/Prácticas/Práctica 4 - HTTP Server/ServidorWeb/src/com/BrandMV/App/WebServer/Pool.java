package com.BrandMV.App.WebServer;

import com.BrandMV.App.Constants.Constants;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * @author BrandMV
 * Threads pool used for create many servers in different ports
 */
public class Pool implements Runnable{
    protected int port;
    protected ServerSocket s = null;
    protected boolean stopped = false;
    protected Thread runningThread = null;
    protected ExecutorService pool = Executors.newFixedThreadPool(Constants.THREADS);

    public Pool(int port){
        this.port = port;
    }

    @Override
    public void run() {
        synchronized (this){
            this.runningThread = Thread.currentThread();
        }
        initServer();
        while(!stopped()){
            Socket cl;
            try{
                //** Accepting connections
                cl = this.s.accept();
                System.out.println(Constants.SERVER_CONNECTION_ACCEPTED);
            }catch (IOException e){
                if(stopped()){
                    System.out.println(Constants.SERVER_CONNECTION_STOPPED);
                    break;
                }
                throw new RuntimeException(Constants.SERVER_CONNECTION_ACCEPTED_ERROR, e);
            }
            this.pool.execute(new Server(cl));
        }
        // * sorted ending
        this.pool.shutdown();
        System.out.println(Constants.SERVER_CONNECTION_STOPPED);

    }

    /**
     * Method that obtains the flag value
     * @return stopped, the flag
     */
    private synchronized boolean stopped(){
        return this.stopped;
    }

    /**
     * Method that changes the flag value to stop the socket connection
     */
    public synchronized void stop(){
        this.stopped = true;
        try {
            this.s.close();
        }catch (IOException e){
            throw new RuntimeException(Constants.SERVER_CONNECTION_STOPPED_ERROR, e);
        }
    }

    /**
     * Method that initialize the server
     */
    private void initServer(){
        try {
            this.s = new ServerSocket(this.port);
            System.out.println(Constants.SERVER_CONNECTION_START);
        }catch (IOException e){
            throw new RuntimeException(String.format(Constants.SERVER_CONNECTION_ERROR, s.getLocalPort()), e);
        }
    }

    public static void main(String[] args) {
        Pool server = new Pool(Constants.PORT);
        new Thread(server).start();
    }
}
