package Practicas.Practica8;

import java.net.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;

public class ChatCliente extends JFrame implements ActionListener{

    String res, pregunta;
	
	JTextField pregun;
	JLabel respuestas;
    JButton enviar;
    
    public ChatCliente()
	{
		super("ChatBoT");
		
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
			Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            ChatInterface netConn=(ChatInterface) registro.lookup(ChatInterface.LOOKUPNAME);
            
            pregunta=pregun.getText();
            res=netConn.preg(pregunta);
			respuestas.setText(res);
			pregun.setText(null);
		
		}
		catch (Exception e)
		{
			respuestas.setText("Error: " + e.getMessage());
			System.out.print("Error: " + e.getMessage());
		}
    }
    
    public static void main(String[] args) {
        new ChatCliente();
    }
    
}
