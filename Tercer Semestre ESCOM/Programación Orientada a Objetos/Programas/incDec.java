import java.awt.event.*;

import java.awt.*;
import java.applet.*;


public class incDec extends Panel implements ActionListener{
    Button binc, bdec; //var. inst.
    Label l;
    int cta;
    public void init(){
        
        binc = new Button("Incrementa"); add(binc);
        binc.addActionListener(this);
        bdec = new Button("Decrementa"); add(bdec);
        bdec.addActionListener(this);
        l= new Label("0"); add(l);
    }

    public void actionPerformed(ActionEvent e){
        Button b= (Button)e.getSource(); //object
        
        if(b == binc) cta++;
        if(b == bdec) cta--;
       l.setText(""+cta);
    }
    public static void main(String[] args) {
        incDec id=new incDec();
        Frame f=new Frame("Incrementar y decrementar");
        id.init();
        f.add("Center", id);
        f.setSize(250,250);
        f.setLocationRelativeTo(null); f.setVisible(true);
        
    }

}