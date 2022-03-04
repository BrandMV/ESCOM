/*
ALUMNO: Meza Vargas Brandon David.
PRÁCTICA: Práctica No. 6.
TEMA: Sockets Servidores.
OPCIÓN: Opción 1, ChatBot Básico o Nano Alexa
FECHA: 21-dic-2020
GRUPO: 2CM1
MATERIA: Programación Orientada a Objetos

*/


package Practicas.Practica6;

import java.net.*;
import java.util.Date;
import java.util.Random;
import java.io.*;

public class ChatServidor{	
	
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
		" Mama, en el colegio me llaman distraido. Juanito, tu vives en la casa de enfrente",
		"Con que juega un bebe vampiro? Con globulos rojos.",
		"Que hace un vampiro conduciendo un tractor? Sembrar el miedo.",
		"En que se parece una bruja y unos dias de vacaciones? En que los dos se van volando.",
		"Como se dice perro en ingles? -Dog. -Y como se dice veterinario? -Muy facil. Dog-tor."
	};
		
		Random r= new Random();
		int aux = 0;
		ServerSocket socketServidor;
		Socket conexion;
		
		PrintStream salida;
		DataInputStream entrada;
		
		String pre;
		
	public void go(){
		try
		{
			socketServidor = new ServerSocket(5000);
			
			while (true)
			{
				conexion = socketServidor.accept();	
				entrada = new DataInputStream(conexion.getInputStream());
				salida = new PrintStream(conexion.getOutputStream());
				pre = entrada.readLine();

				if(pre.equals("Cuenta un chiste")){
					int n = r.nextInt(11);
					salida.println(chistes[n]);
				}
				for (int i=0;i<9;i++)
				{
					
					if(pre.equals(preguntas[i]))
						salida.println(respuestas[i]);
					else
						aux = 1;

				}
				
				if(aux== 1)
					salida.println("No tengo una respuesta :(");
				conexion.close();		
			}
		}
		catch(Exception e)
		{
			System.out.println("Error: " + e.getMessage());
		}

	}

	public static void main(String args[]){	
		new ChatServidor().go();
	}
}