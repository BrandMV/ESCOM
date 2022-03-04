import java.awt.event.*;
import java.awt.*;
import java.applet.*;

public class gato extends Panel implements ActionListener{
    int turno=0;
    Button botones[];
    String signos[]={"X","O"};
    
    public gato(){
        
        setLayout(new GridLayout(3,3));
        botones=new Button[9]; //reservo memoria para 9 botones botones=(Button **)malloc(sizeof(Button*)*9), es decir asigna memoria al arreglo ;
        for(int i=0;i<botones.length;i++){
            add(botones[i]=new Button(""+i)); //botones[i]=(Button *)malloc(sizeof(Button)); new asigna memoria para un boton y llama al constructor
            botones[i].addActionListener(this); //el escucha va a ser un panel
        }

    }
    public static void main(String[] args) {
        Frame f= new Frame("Gato");
        f.add("Center", new gato());
        f.setSize(250,250); f.setVisible(true);
        f.setLocationRelativeTo(null);
        
    }
  
    public void actionPerformed(ActionEvent e) {
        Button btn=(Button)e.getSource(); //Object, las fuentes de eventos son tipo buton, es decir, botones
        btn.setLabel(signos[turno]);
        //btn.setEnabled(false);
        btn.removeActionListener(this);
        turno=1-turno;
        
    }
    
}
