import java.io.Serializable;
public class Tirada implements Serializable{ //se serializa el objeto cuando lo mandmos por la red o lo guardamos en un archivo
    String programa;
    String nick;
    private int posicion;

    public Tirada(String programa, String nick, int posicion)
    {
        this.programa=programa;
        this.nick=nick;
        this.posicion=posicion;
    }
    public String getPrograma(){
        return programa;
    }
    public String getNick(){
        return nick;
    }
    public int getPosicion(){
        return posicion;
    }
}
