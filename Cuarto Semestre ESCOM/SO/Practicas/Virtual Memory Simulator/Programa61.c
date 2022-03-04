#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MARCOS 8;
#define PAGINAS 16;

typedef struct tabla{ //se crea la estructura de la tabla de marcos y paginas
    int indice; //guarda el indice de pagina o marco
    int referencia; //guarda la pagina o marco al que se hace referencia
    int estado; //para mantener control de la pagina en la tabla 1: esta, 0: no esta
    // int m;
    // int r;
    struct tabla *sig; //estrucutra que apunta a la siguiente pagina o marco
}tabla;


int pgs; //indica el total de paginas en marcos

void bitsPagina(int indiceP){ //funcion que hace la conversión de indice a binario
    int bits=3; //indica los bits del indice de pagina 
    while(bits >= 0){ //este ciclo while hace la conversion a binario
        if(indiceP & (((long int)1) << bits)) //si el indice y el recorrido regresan verdadero se regresa 1 si no 0
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void bitsMarco(int indiceM){ //funcion que hace la conversión de indice a binario
    int bits=2; //cantidad de bits del indice de marco
    while(bits >= 0){
        if(indiceM & (((long int)1) << bits))
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void desplazamiento(int n){
    int bits = 11;//cantidad de bits de los bits de desplazamiento
    while(bits >= 0){
        if(n & (((long int)1) << bits))
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void printDesp(int indiceP, int indiceM){ //esta funcion realiza los 4096 direccionamientos
    int i;

    for(i=0;i<4096;i++){ //for que va de 0 hasta las 4096 direcciones de la pagina
        bitsPagina(indiceP);
        printf("\t");
        desplazamiento(i);
        printf("\t ------ \t");
        bitsMarco(indiceM);
        printf("\t");
        desplazamiento(i);
        printf("\n");
    }
}
tabla *iniTabla(){ //funcion que crea la tabla
    return NULL;
}

tabla *crearPag(int i){ //esta funcion crea una pagina
    tabla *aux = (tabla*) malloc(sizeof(tabla)); //reservo memoria para la pagina
    aux->indice = i; //se asigna el indice de las paginas en memoria virtual
    aux->estado = 1; //esta en la tabla de paginas
    aux->referencia = -1; //de inicio no esta en ningun marco de pagina
    aux->sig = NULL; //se apunta a la siguiente pagina
    return aux;
}
tabla *agregarPag(tabla *tblPaginas, tabla *nuevaPag){ //esta funcion agrega la pagina a la tabla de paginas
    if(tblPaginas == NULL){ //si no hay nada dentro de la tabla se agrega la pagina al inicio
        tblPaginas = nuevaPag;
    }else{ //si ya hya una pagina se agrega en el siguiente nodo 
        nuevaPag->sig = tblPaginas;
        tblPaginas = nuevaPag;
    }
    return tblPaginas;
}
void mostrarT(tabla *tblPaginas){ //imprime la tabla de paginas ya establecidas al inicio
    tabla *aux = tblPaginas; //usamos aux para recorrer la tabla e imprimirla
    while(aux!=NULL){
        printf("\t\tindice: %d\t\tEstado: %d\t\tMarco referenciado: %d\n", aux->indice, aux->estado, aux->referencia);
        aux=aux->sig;
    }
}
void mostrarTM(tabla *tblMarcos){ //imprime la tabla de marcos de magina
    tabla *aux = tblMarcos; //usamos aux para recorrer la tabla e imprimirla
    if(aux ==  NULL) // para verificar si ya se ha movido una pagina a la memoria fisica
        printf("Aun no se ha movido ninguna pagina a RAM\n");
    while(aux!=NULL){
        printf("\t\tindice: %d\t\tPagina referenciada: %d\n", aux->indice, aux->referencia);
        aux=aux->sig;
    }
}
tabla* FIFO(tabla *tblMarcos, int dire){ //funcion que establece que marco sale y cual entra
    tabla *aux;
    if((tblMarcos !=NULL) && (tblMarcos -> indice == 0)){
        aux = tblMarcos;
        aux->referencia = dire; //se asigna la nueva pagina a la que el primer marco hara referencia
        tblMarcos = aux;   
        // printf("pgs %d %d\n", tblMarcos->indice, tblMarcos->referencia);
        return tblMarcos;
    }
   
}
tabla *insertP(int dire){ //esta funcion solo crea el marco de pagina pero no agrega la pagina
    if(pgs < 8){
        tabla *aux = (tabla*) malloc(sizeof(tabla)); //reservo memoria para la pagina
        aux->indice = pgs; //el indice de marco se va creando conforme las paginas que se van agregando
        aux->estado = 1; //el estado se vuelve uno si la pagina este en la tabla de marcos
        aux->referencia = dire; //se asigna el indice de pagina a la que se hace referencia
        aux->sig == NULL;   //se apunta al siguiente marco
        pgs++;  //se incrementa la cantidad de paginas en marcos
        return aux;

    }else{ //si la memoria fisica esta llena, se procede a realizar un remplazo de paginas por FIFO
        printf("Memoria fisica llena, se hara un remplazo de marco de pagina\n");
        tabla *aux = (tabla*) malloc(sizeof(tabla));
        aux = FIFO(aux, dire); 
        pgs++;
        return aux;
    }
    
}
tabla *agregarMarco(tabla *tblMarcos, tabla *nuevoMarco){ //aqui se agrega la pagina a un marco de pagina
    if(tblMarcos == NULL) //si la tabla de marcos esta vacia se agrega al inicio
        tblMarcos = nuevoMarco;
    else{//si no esta vacia se agrega en el siguiente nodo
        nuevoMarco->sig = tblMarcos;
        tblMarcos = nuevoMarco;
    }
    return tblMarcos;
}
tabla *addFIFO(tabla *tblMarcos, tabla *nuevoMarco){ //se sobreescribe el primer marco ya que fue el primero en ingresar
    tabla* ant, *aux;
    aux = tblMarcos;
        while((aux != NULL) && (nuevoMarco->indice != aux->indice)){ //se hace un while para recorrer los marcos hasta que haya coincidencia
            ant =aux;
            aux = aux->sig; //se van recorriendo los marcos
            // printf("indi %d marco%d\n",aux->indice, nuevoMarco->referencia);
        }
        if(aux!=NULL){ //cuando se encuentra una coincidencia y no es nula se modifica la referencia
            aux->referencia = nuevoMarco->referencia;
        }
    // printf("indi %d marco%d\n",nuevoMarco->indice,nuevoMarco->referencia);
    // printf("indi %d marco%d\n",tblMarcos->indice,tblMarcos->referencia);
    return tblMarcos;
}


tabla *busca(tabla *tblPaginas, int marco, int indi){ //esta funcion busca el indice de marco al que la pagina hara referencia
    tabla *aux, *ant; //se crean auxiliares para no modificar la tabla original
    if(tblPaginas != NULL &&  (marco == tblPaginas->indice)){ //se verifica si el indice de pagina es el mismo que el de pagina
       // printf("indi %d marco%d\n",tblPaginas->indice, marco);
        aux = tblPaginas; //el auxiliar es para no modificar la tabla original
        aux->referencia = indi; //se modifica el marco a l que la pagina hace referencia
        aux->estado = 0;
        tblPaginas = aux; //ahora si se guarda en la tabla original con la referencia actualizada
        printDesp(tblPaginas->indice, indi);// se realiza el direccionamiento de bits
        return tblPaginas;
    }else{ 
        aux = tblPaginas;
        while((aux != NULL) && (marco != aux->indice)){ //se hace un while para recorrer las paginas hasta que haya coincidencia
            ant =aux;
            aux = aux->sig; //se van recorriendo las tablas de pagina
            //printf("indi %d marco%d\n",aux->indice, marco);
        }
        if(aux!=NULL){ //cuando se encuentra una coincidencia y no es nula se modifica el marco referenciado
            aux->referencia = indi;
            aux->estado = 0;
            printDesp(aux->indice, indi);// se realiza el direccionamiento de bits
        }

        return tblPaginas; //se regresa la tabla de paginas con los marcos a los cuales se referencian
    }

    
}

int verifica(tabla *tblPaginas, int dire){ //se verifica si la pagina sigue en la tabla o ya se movio
    tabla *aux, *ant; //auxiliares para no modificar la tabla original
    if(tblPaginas != NULL && (dire == tblPaginas->indice)){ //se verifica el estado de la primera pagina
        if(tblPaginas->estado == 1) //si la pagina esta se regresa un 1 si ya fue movida un 0
            return 1;
        else
            return 0;
    }else{
        while((tblPaginas != NULL) && (dire != tblPaginas->indice)){ //recorre todas las paginas
            tblPaginas = tblPaginas->sig; 
        }
        if(tblPaginas != NULL){ //si esta la pagina se regresa un 1 si no un 0
            if(tblPaginas->estado==1)
                return 1;
            else
                return 0;
        }
    }
}


int main(){
    int opc, i, dire, esta;
    tabla *tblPaginas = iniTabla(); //creamos la tabla de paginas
    tabla *tblMarcos = iniTabla();  //creamos la tabla de marcos

    for(i=0;i<16;i++){ //se llena la tabla de paginas automaticamente con 16 paginas
        tabla *nuevaPag = crearPag(i);
        tblPaginas = agregarPag(tblPaginas, nuevaPag);
    }
    //tblPaginas=tblPaginas->sig;
    //printf("1aver %d\n", tblPaginas->indice);
    
    while(opc >= 0){ //while para mostrar un menu del programa
        printf("\nOperaciones con la memoria:\n");
        printf("1. Ver tablas\n");
        printf("2. Mover pagina a memoria fisica\n");
        printf("3. Salir\n");
        scanf("%d",&opc);
        if(opc > 4)
            printf("Opcion no valida\n");

        switch (opc)
        {
        case 1:
            system("clear");
            printf("\t\tTabla de paginas\n\n");
            mostrarT(tblPaginas); //funcion que imprime la tabla de paginas
            printf("\n\t\tTabla de Marcos de pagina\n\n");
            mostrarTM(tblMarcos);   //funcion que imprime la tabla de marcos
            break;
        
        case 2:
            system("clear");
            printf("Ingrese la pagina a mover a RAM 0-15\n");
            scanf("%d", &dire);
            if(dire>15){ //solo se pueden mover las paginas que hay en la tabla
                printf("Solo hay 16 paginas en memoria virtual\n");
                break;
            }
                
            else{
                esta = verifica(tblPaginas, dire); //verifica si la pagina esta en la tabla de paginas
                if(esta == 1){ //si si esta la pagina se procede a mover
                    tabla *nuevoMarco = insertP(dire);
                    
                    if(pgs < 9){
                        tblMarcos = agregarMarco(tblMarcos, nuevoMarco); //se agrega la pagina a un marco de pagina
                        tblPaginas = busca(tblPaginas, tblMarcos->referencia, tblMarcos->indice); 
                        //funcion que actualiza a que marco hace referencia la pagina movida
                    }else{
                        tblMarcos = addFIFO(tblMarcos, nuevoMarco); //añade a la tabla el nuevo marco
                        //se hace el algoritmo fifo para sobreescribir el primer marco de pagina
                        // printf("%d %d\n", tblMarcos->referencia, tblMarcos->indice);
                        tblPaginas = busca(tblPaginas, nuevoMarco->referencia, nuevoMarco->indice); 
                    }
  
                    break;
                }else{
                    printf("Ya se ha movido esta pagina\n");
                    //se imprime en caso de que se quiera mover una pagina que ya no esta en la tabla 
                    break;
                }
                
            }

        case 3:
            return 0; //para salir del programa
        }
    }

    return 0;
}
