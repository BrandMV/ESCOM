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

int main(int argc, char *argv[]) {
	int n,i,dato,o,op;
	arbol *p=NULL;
	while(op>=0){
	printf("Operaciones Basicas con un arbol binario\n");
	printf("1= Crear arbol\n");
	printf("2= Insertar en el arbol\n");
	printf("3= Suprimir un dato\n");
	printf("4= Ver arbol\n");
	printf("5= Recorridos\n");
	printf("6= Salir\n");
	printf("Elija una opcion: \n");
	scanf("%d",&op);
	if(op>6){
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
			return 0;
		}
	}
}
