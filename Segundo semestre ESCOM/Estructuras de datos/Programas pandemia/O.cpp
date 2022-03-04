#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <malloc.h>

typedef struct nodo arbol;
typedef struct nodo *pNodo;

struct nodo{
int dato;
arbol *izquierdo;
arbol *derecho;	
};

void ver(int nivel,struct nodo *p);
arbol *nuevo();
arbol *insertar(int dato,arbol *p);
arbol *cambia(arbol *p, arbol *s);
arbol *suprimir(arbol *p,int dato);
void pre_orden(arbol *p);
void en_orden(arbol *p);
void post_orden(arbol *p);
int num_nodos(arbol *p);
void alturaArbol (arbol *raiz, int *altura);
void auxAltura (arbol *raiz, int a, int *altura);
int esHoja(arbol *raiz);
arbol *arbolEspejo(arbol q);
/*arbol *espejo(int dato,arbol *p);
int espejo_ver(int nivel,struct nodo *p);*/

arbol *nuevo(){
arbol *q= (arbol *)malloc(sizeof(arbol));
if(!q){
	printf("\n Memoria insuficiente");
	return 0;
}
return q;
}

arbol *insertar(int dato,arbol *p){
	if(p==NULL){
		p=nuevo();
		p->dato=dato;
		p->izquierdo=NULL;
		p->derecho=NULL;
		return(p);
	}
	if(dato<p->dato)
		p->izquierdo=insertar(dato,p->izquierdo);
	else
		p->derecho=insertar(dato,p->derecho);
	return(p);
}

void ver(int nivel,struct nodo *p){
	int i;
	if(p!=NULL){
		ver(nivel+1,p->derecho);
		printf("\n");
		for(i=0;i<nivel;i++)
			printf("  ");	
		printf("%d",p->dato);
		ver(nivel+1,p->izquierdo);
	}
}

arbol *cambia(arbol *p, arbol *s){
	arbol *temp;
	if(s->derecho!=NULL){
		s->derecho=cambia(p,s->derecho);
	}
	else{
		temp=s;
		p->dato=s->dato;
		s=s->izquierdo;
		free(temp);
	}
	return s;
}
	
arbol *suprimir(arbol *p,int dato){
	arbol *temp;
	if(p==NULL){
		printf("Arbol vacio\n");
	}
	else
		if(dato<p->dato)
			p->izquierdo=suprimir(p->izquierdo,dato);
		else
		if(dato>p->dato){
					p->derecho=suprimir(p->derecho,dato);
		}
		else{
			temp=p;
			if(temp->derecho==NULL){
				p=temp->izquierdo;
				free(temp);
			}
			else
			if(temp->izquierdo==NULL){
				p=temp->derecho;
				free(temp);
			}
			else{
				temp->izquierdo=cambia(temp,temp->izquierdo);
			}
		}
	return p;
}

void pre_orden(arbol *p){
	if(p!=NULL){
		printf("%d ",p->dato);
		pre_orden(p->izquierdo);
		pre_orden(p->derecho);
	}
}

void en_orden(arbol *p){
	if(p!=NULL){
		en_orden(p->izquierdo);
		printf("%d ",p->dato);
		en_orden(p->derecho);
	}
}

void post_orden(arbol *p){
	if(p!=NULL){
		post_orden(p->izquierdo);
		post_orden(p->derecho);
		printf("%d ",p->dato);
	}
}

int num_nodos(arbol *p){
	if(p==NULL){
		return 0;
	}
	return(num_nodos(p->izquierdo)+1+num_nodos(p->derecho));
}

int esHoja(arbol *raiz){
    if (!raiz->derecho && !raiz->izquierdo)
       return 1;
    else
        return 0; 
}
 
 void auxAltura (arbol *raiz, int a, int *altura){
    if(raiz->izquierdo){
        auxAltura(raiz->izquierdo, a+1, altura);
    }
    if(raiz->derecho){
        auxAltura(raiz->derecho, a+1, altura);
    }
    if(esHoja(raiz) && a>*altura){
        *altura=a;
    }
}

//altura de arbol
void alturaArbol (arbol *raiz, int *altura){
    *altura=0;
    auxAltura(raiz, 0, altura);
}

/*arbol *espejo(int dato,arbol *p){
	if(p==NULL){
		p=nuevo();
		p->dato=dato;
		p->izquierdo=NULL;
		p->derecho=NULL;
		return(p);
	}
	if(dato<p->dato)
		p->derecho=espejo(dato,p->derecho);
	else
		p->izquierdo=espejo(dato,p->izquierdo);
	return(p);
}

int espejo_ver(int nivel,struct nodo *p){
	int i=0;
	
	int k[num_nodos(p)];
	if(p!=NULL){
		espejo_ver(nivel+1,p->derecho);
		//for(i=0;i<nivel;i++)
			//printf("  ");	
			k[i]=p->dato;
			i++;
		espejo_ver(nivel+1,p->izquierdo);
	}
}*/

arbol *arbolEspejo(arbol *q)
{
    arbol *temp;

    if(q!=NULL)
    {
          temp = q->izquierdo;
          q->izquierdo = arbolEspejo(q->derecho);
          q->derecho = arbolEspejo(temp);
    }
    return q;
}
 
int main(int argc, char *argv[]) {
	int n,i,dato,o,op,aux;
	arbol *p=NULL;
	while(op>=0){
	printf("Operaciones Basicas con un arbol binario\n");
	printf("1= Crear arbol\n");
	printf("2= Insertar en el arbol\n");
	printf("3= Suprimir un dato\n");
	printf("4= Ver arbol\n");
	printf("5= Recorridos\n");
	printf("6= No. nodos y altura\n");
	printf("7 =Espejo de arbol\n");
	printf("8= Salir\n");
	printf("Elija una opcion: \n");
	scanf("%d",&op);
	if(op>8){
		printf("Opcion no valida\n");
		system("pause");
		system("cls");
	}	
	switch(op){
		case 1:
			system("cls");
			printf("Numero de nodos del arbol: \n");
			scanf("%d",&n); 
			for(i=0;i<n;i++){
				printf("\nElemento No. %d: ",i+1);
				scanf("%d",&dato);
				p=insertar(dato,p);
			}
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			printf("\nElemento: \n");
			scanf("%d",&dato);
			p=insertar(dato,p);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			printf("Dato a Suprimir: ");
			scanf("%d",&dato);
			suprimir(p,dato);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			printf("Arbol binario: \n");
			ver(0,p);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("Recorrido en Pre-orden:\n");
			pre_orden(p);
			printf("\n");
			printf("Recorrido en Orden:\n");
			en_orden(p);
			printf("\n");
			printf("Recorrido en Post-Orden:\n");
			post_orden(p);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			num_nodos(p);
			printf("Nodos: %d\n",num_nodos(p));
			alturaArbol (p,&aux);
    		printf ("La Altura del Arbol es: %d\n", aux);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			ver(0,arbolEspejo(p));
			printf("\n");
			arbolEspejo(p);
			system("pause");
			system("cls");
			break;
		case 8:
			return 0;
		}
	}
}
