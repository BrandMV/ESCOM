/*
ALUMNO: Meza Vargas Brandon David.
PRÁCTICA: Práctica No. 7.
TEMA: JDBC.
OPCIÓN: Opción 1, Insertar Perros en una base de datos.
FECHA: 07-01-21
GRUPO: 2CM1
MATERIA: Programación Orientada a Objetos

*/

package Practicas.Practica7;

import java.sql.*;
import javax.swing.*;
import java.awt.event.*;

public class perros extends JFrame implements ActionListener{

    JLabel n,r,e,g;
    JTextField no,ra,ed,ge;
    JButton con, ins;
    Connection cone;
    int edad;
    Statement st;
    String nombre, raza, genero;

    public perros(){

        super("Insertar perros a BD");
		
        n= new JLabel("Nombre: ");
        r= new JLabel("Raza: ");
        e= new JLabel("Edad: ");
        g= new JLabel("Genero: ");

        no=new JTextField();
        ra= new JTextField();
        ed=new JTextField();
        ge= new JTextField();
        
        con= new JButton("Conectar");
        ins= new JButton("Insertar");
        
        con.addActionListener(this);
        ins.addActionListener(this);
        

		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setSize(450,300);
		setVisible(true);

        init();
    }

    void init(){

        setLayout(null);
	
        n.setBounds(5,15,60,10); add(n);
        no.setBounds(80,10,50,20); add(no);
        r.setBounds(5,55,50,10); add(r);
        ra.setBounds(80,50,50,20);add(ra);
        e.setBounds(5,95,50,10); add(e);
        ed.setBounds(80,90,50,20);add(ed);
        g.setBounds(5,135,50,10); add(g);
        ge.setBounds(80,130,50,20);add(ge);

        con.setBounds(5, 180, 90,20); add(con);
        ins.setBounds(120, 180, 90,20); add(ins);

    }

    public void actionPerformed(ActionEvent a){

        JButton btn= (JButton) a.getSource();

       if(btn==con){
           try {
               Class.forName("com.mysql.jdbc.Driver");
               cone= DriverManager.getConnection("jdbc:mysql://localhost:3306/perros", "root", "");
               con.removeActionListener(this);
           } catch (Exception e) {
               e.printStackTrace();
           }
       }
       else{
           nombre= no.getText();
           raza=ra.getText();
           edad=Integer.parseInt(ed.getText());
           genero=ge.getText();

           try {
               st=cone.createStatement();
               st.executeUpdate("Insert into perro (nombre, raza, edad, genero) Values ('"+nombre+"'"+", '"+raza+"'"+","+edad+","+"'"+genero+"')");
           } catch (Exception e) {
            e.printStackTrace();
           }
       }

    }
    public static void main(String[] args) {
        new perros();
    }
    
}
