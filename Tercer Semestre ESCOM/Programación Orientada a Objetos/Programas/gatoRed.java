import java.awt.event.*;
import java.awt.*;

public class gatoRed extends Panel implements LeeRed, ActionListener{
    int turno;
    Button botones[], conecta;
    String signos[]={"X","O"};
    private Red r;

    public gatoRed(){
        Panel p1,p2;
        turno=0;
        p1=new Panel(); p2=new Panel();
        p1.setLayout(new GridLayout(3,3));
        p2.setLayout(new BorderLayout()); //podemos acomodar cosas al norte, sur, centro, este y oeste
        botones=new Button[9];
        for(int i=0; i< botones.length;i++){
            p1.add(botones[i]=new Button(""+i));
            botones[i].setEnabled(false);
            botones[i].addActionListener(this); //el boton se registra con el boton i-esimo
        }
        conecta= new Button("Conecta");
        conecta.addActionListener(this);
        p2.add(p1, BorderLayout.NORTH);
        p2.add(conecta, BorderLayout.SOUTH);
        add(p2);
    }

    public static void main(String[] args) {
        Frame f= new Frame("Gato");
        f.add("Center", new gatoRed());
        f.setSize(250,250); f.setVisible(true);
    }

    public void leeRed(Object obj){ //parte de red
        Tirada t=(Tirada)obj;
        int k=t.getPosicion();
        if(botones[k].isEnabled()){
            botones[k].setLabel(signos[turno]);
            botones[k].setEnabled(false);
            turno=1-turno;
        }
    }

    public void actionPerformed(ActionEvent e) {
        Button btn=(Button)e.getSource();
        if(btn==conecta) conectar();
        else{
            btn.setLabel(signos[turno]); //cambiamos la etiqueta al boton de acuerdo al turno
            btn.setEnabled(false); //desactivamos ese boton para que no puedan volve a tirar en esa posicion del tablero
            turno=1-turno; //si turno es uno, despues cera 0
            int i= Integer.parseInt(e.getActionCommand());
            r.escribeRed(new Tirada("Gato", "jug1",i)); //comunica maq remota
        }
    }

    void conectar(){
        for(int i=0; i<botones.length; i++)
            botones[i].setEnabled(true);
        r=new Red(this); //participa un objeto de tipo gatoRed
                            //gral. un objeto de una clase que implementa la interfaz LeeRed(polimorfismo)
    }

    
}
