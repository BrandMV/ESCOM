package Practicas.Practica8;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;
import java.util.Random;

public class ChatServer extends UnicastRemoteObject implements ChatInterface{
    String preguntas[]= {
        "Como te llamas?",
        "En que ciudad vives?",
        "Tienes sentimientos?",
        "Quien te creo?",
        "Harias mi tarea?",
        "Que haces?",
        "Cual es tu edad?",
        "Dame la fecha",
        "Tienes un pasatiempo?"
    };

    String respuestas[]={
        "Pedrito Sola",
        "No en una ciudad, pero vivo en el corazon de todos",
        "Los robots no tenemos sentimientos",
        "El que hizo esta practica, Brandon Meza",
        "No lo creo jaja",
        "Viendo que me preguntas",
        "Tengo una semana",
        "Claro, estamos a "+ new Date(),
        "Navegar por la red"
    };

    String chistes []={
    "Habia un perro de goma que cuando se rascaba se borraba.",
    "Habia una vez un hombre tan pequeño que se subio encima de una canica y dijo: El mundo es mio!",
    "- Sabes que mi hermano anda en bicicleta desde los cuatro anios? Mmm, ya debe estar lejos.",
    "- Pedrito, que planeta va despues de Marte? Miercoles",
    " Cual es el pez que huele mucho? El Peztoso!!!",
    };

    Random r= new Random();
    int aux = 0;

    public ChatServer() throws RemoteException{
        super();
    }

    public String preg(String pre) throws RemoteException{

        if(pre.equals("Cuenta un chiste")){
            int n = r.nextInt(5);
            return chistes[n];
        }
        for (int i=0;i<9;i++)
        {
            
            if(pre.equals(preguntas[i]))
                return respuestas[i];
            else
                aux = 1;

        }
        if(aux== 1)
            return "No tengo una respuesta :(";

        return "";
    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(ChatInterface.LOOKUPNAME, new ChatServer());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }
    
}
