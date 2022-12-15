       import java.util.*;

       public class DriverAFD {
         public static void main(String[] args) {
           ArgumentosToken tm = new ArgumentosToken(args);
           AFD m = new AFD(tm);
           m.activarAFD();
         }
       }

       class ArgumentosToken {
         private int indice;
         String entrada;
         public ArgumentosToken(String[] args) {
           if(args.length > 0)
             entrada = args[0];
           else
             entrada = "";
           indice = 0;
           System.out.println("entrada = " + entrada);
         }
         public char getSiguienteToken() {
           if(indice < entrada.length())
             return entrada.charAt(indice++);
           else
             return '$';
         }
       } 

       class AFD {
         ArgumentosToken tm;
         private char tokenActual;
         public AFD(ArgumentosToken tm) {
           this.tm = tm;
         }
         public void avanzar() {
           tokenActual = tm.getSiguienteToken();
         }
         public void activarAFD() {
           int estadoActual = 0;
           avanzar();
    
           while(tokenActual != '$') {
             switch(estadoActual) {
               case 0:
                 if(tokenActual == 'b') estadoActual = 1;
                 else if(tokenActual == 'c') estadoActual = 1;
                 break;
               case 1:
                 if(tokenActual == 'b') estadoActual = 2;
                 else if(tokenActual == 'c') estadoActual = 3;
                 break;
               case 2:
                 if(tokenActual == 'b') estadoActual = 4;
                 else if(tokenActual == 'c') estadoActual = 4;
                 break;
               case 3:
                 if(tokenActual == 'b') estadoActual = 4;
                 else if(tokenActual == 'c') estadoActual = 3;
                 break;
               case 4:
                 if(tokenActual == 'b') estadoActual = 4;
                 else if(tokenActual == 'c') estadoActual = 4;
                 break;
             }
             avanzar();
           }
           if(estadoActual == 2 || estadoActual == 3)
             System.out.println("Acep");
           else
             System.out.println("rechazado");
         }
       }
