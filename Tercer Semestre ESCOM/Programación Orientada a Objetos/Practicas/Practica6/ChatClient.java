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
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ChatClient extends JFrame implements ActionListener{

	Socket conexion;
	
	PrintStream salida;
	DataInputStream entrada;
	String res;
	
	JTextField pregun;
	JLabel respuestas;
	JButton enviar;

	public ChatClient()
	{
		super("ChatBoT Basico");
		
		pregun = new JTextField("Pregunta algo...");
		respuestas = new JLabel("Hola!");
		enviar = new JButton("Preguntar");
		
		enviar.addActionListener(this);

		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setSize(600,300);
		setVisible(true);
		init();
	}
	
	void init(){	
		setLayout(null);
	
		respuestas.setBounds(0,150,550,30);
		pregun.setBounds(0,200,450,30);
		enviar.setBounds(460,205,100,20);
		add(respuestas);add(pregun);	add(enviar);
	}
	public void actionPerformed(ActionEvent a)
	{
		try
		{
			conexion = new Socket("localhost", 7777);
			entrada = new DataInputStream(conexion.getInputStream());
			salida = new PrintStream(conexion.getOutputStream());
			
			salida.println(pregun.getText());
			respuestas.setText(pregun.getText());
			pregun.setText(null);
			res = entrada.readLine();
			respuestas.setText(res);
		}
		catch (Exception e)
		{
			respuestas.setText("Error: " + e.getMessage());
			System.out.print("Error: " + e.getMessage());
		}
	}
	
public static void main(String args[])
	{
		new ChatClient();
	}
}
