/*
    ALUMNO: Meza Vargas Brandon David.
    PRÁCTICA: Práctica No. 1
    TEMA: GUI (Interfaz Gráfica de Usuario)
    OPCIÓN: Opción 3, convertidor de temperatura.
    FECHA DE ENTREGA: 06-nov-2020
    GRUPO: 2CM1
    MATERIA: Programación Orientada a Objetos
*/


package Practicas.Practica1;

import java.awt.Color;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class temp extends JFrame{

    JLabel titu,a,resu;
    JButton btn1;
    JTextField valor;
    JComboBox unid, unid2;
    public temp(){
        setSize(500,500);
        setTitle("Convertidor de temperatura");
        setLocationRelativeTo(null);
        init();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        
    }

    private void init(){
        JPanel panel = new JPanel();
        panel.setBackground(new Color(192, 57, 43));
        this.getContentPane().add(panel);    
        panel.setLayout(null);           

        titu= new JLabel("CONVERTIDOR DE TEMPERATURA", SwingConstants.CENTER);
        panel.add(titu);
        titu.setForeground(Color.WHITE);
        titu.setFont(new Font("arial black",Font.BOLD,20));
        titu.setBounds(40,0,400,50);
        btn1 = new JButton();
        btn1.setBounds(370,80,100,20);
        btn1.setText("Convertir");
        btn1.setForeground(new Color(253, 254, 254));
        btn1.setBackground(new Color(44, 62, 80));
        panel.add(btn1);
        btn1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        } );

        valor = new JTextField();
        valor.setBounds(10,80,80,20);
        valor.setText("0");
        panel.add(valor);

        String [] unidades = {"Centigrados", "Kelvin"};

        unid = new JComboBox(unidades);
        unid.setBounds(110,80,100,20);
        panel.add(unid);
        unid2 = new JComboBox(unidades);
        unid2.setBounds(260,80,100,20);
        panel.add(unid2);

        a= new JLabel("-->",SwingConstants.CENTER);
        a.setForeground(Color.white);
        a.setFont(new Font("arial black",Font.BOLD,20));
        a.setBounds(210,80,50,20);
        panel.add(a);

        resu= new JLabel("",SwingConstants.CENTER);
        resu.setForeground(Color.white);
        resu.setFont(new Font("arial black",Font.BOLD,20));
        resu.setBounds(20,140,400,40);
        panel.add(resu);
    }

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        
        String box1 = (String)unid.getSelectedItem();
        String box2 = (String)unid2.getSelectedItem();
         
        if(box1.equals("Centigrados") && box2.equals("Kelvin"))
        {
            double cen= Double.parseDouble(valor.getText());
            double kel=(double) (cen + 273.15);
            String kelvin= String.valueOf(kel);
            resu.setText(valor.getText() + "C° es igual a "+kelvin+"k°");
        } 
        else
        if(box1.equals("Centigrados") && box2.equals("Centigrados"))
        {
            double cen= Double.parseDouble(valor.getText());
            resu.setText(String.valueOf(valor.getText() + "c° es igual a "+cen+"c°"));
        } 
         
        if(box1.equals("Kelvin") && box2.equals("Centigrados"))
        {
            double kel= Double.parseDouble(valor.getText());
            double cen=(Double)(kel-273.15);
            resu.setText(String.valueOf(valor.getText() + "k° es igual a "+cen+"c°"));
        } 
        else  
        if(box1.equals("Kelvin") && box2.equals("Kelvin"))
        {
            double kel= Double.parseDouble(valor.getText());
            resu.setText(String.valueOf(valor.getText() + "k° es igual a "+kel+"k°"));
        } 
    }     
        public static void main(String[] args) {
            temp t= new temp();
    
            t.setVisible(true);
        }
        
    
}


