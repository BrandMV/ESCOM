#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct nodos nodo;
struct nodos{
	int dato;
	nodo *siguiente;
};



nodo *nuevo();
int hashl(int dato);
nodo *insertar(int dato);
void eliminar(int dato);
nodo *buscar(int dato);
void error();
void menu();



nodo *nuevo(){
	nodo *q=(nodo *)malloc(sizeof(nodo));
	if(!q) error();
	return (q);
}

nodo **tablaH;
int tam; //tamaño tabla hash


//meotodo de division
int hashl(int dato){
	return(dato % tam);
}

nodo *insertar(int dato){
	nodo *p, *q;
	int clave;
	clave=hashl(dato);
	p=nuevo();
	q=tablaH[clave];
	tablaH[clave]=p;
	p->siguiente=q;
	p->dato=dato;
	return p;
}

void eliminar(int dato){
	nodo *q, *p;
	int clave;
	q=0;
	clave=hashl(dato);
	p=tablaH[clave];
	
	while(p && !(p->dato==dato))
	{
		q=p;
		p=p->siguiente;
	}
	
	if(!p) 
		return;
		
	if(q) 
		q->siguiente=p->siguiente;
	else
		tablaH[clave]=p->siguiente;
	free(p);
}

nodo *buscar(int dato){
	nodo *p;
	p=tablaH[hashl(dato)];
	while(p && !(p->dato==dato))
		p=p->siguiente;
	return p;
}

void error()
{
	printf("Error: no hay suficiente memoria");
}

void menu(){
	printf("1. Insertar datos\n");
	printf("2. Buscar un dato\n");
	printf("3. Eliminar un dato\n");
	printf("4. Ver datos\n");
	printf("5. Salir\n");
	printf("¿Que desea realizar?: ");
}

int main(int argc, char *argv[]) {
	
	int i, opc, *a, max, dato;
	nodo *p;
	tam=20;
	max=0;

	
	while(1)
	{
		menu();
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1:
				for(i=max-1;i>=0;i--)
					eliminar(a[i]);
					
				printf("\nCuantos datos quiere?: ");
				scanf("%d",&max);
				
				if((a=malloc(max*sizeof(*a))) == 0)
				{
					perror ("No hay suficiente memoria\n");
					exit(1);
				}
				if((tablaH = malloc(tam*sizeof(nodo *))) == 0)
				{
					perror ("No hay suficiente memoria\n");
					exit(1);
				}
				
				for(i=1;i<=max;i++)
				{
					
					a[i]=rand() %100;
					printf("\n\tDato %d : %d",i,a[i]);
					insertar(a[i]);
				}
				
				printf("\n");
				
		
				break;
			
			case 2:
				printf("\nIntroduce el dato a buscar: ");
				scanf("%d", &dato);
				p=buscar(dato);
				if(p)
					printf("\nEl dato %d se encontro", p->dato);
				else
					printf("\nEl dato %d no se encontro", dato);
					
					printf("\n");
			
				break;
			case 3:
				printf("\nIntroduce el dato a eliminar: ");
				scanf("%d", &dato);
				p=buscar(dato);
				if(p)
				{
					eliminar(dato);
					printf("\nEl dato %d se elimino", dato);
				}
				else
					printf("\nEl dato %d no se encontro", dato);
				printf("\n");	
		
				break;
			case 4:
				printf("\n\tDato: Hash: Dato:\n\t", hashl(p->dato),p->dato);
				for(i=max;i>=0;i--)
				{
					p=buscar(a[i]);
					if(p)
						printf("\n\tDato: %02d : %d", hashl(p->dato),p->dato);
				}
				printf("\n");
			
				break;
			case 5:
				for(i=max-1;i>=0;i--)
					eliminar(a[i]);
					exit(1);
					break;
		}
	}
	
	
	
	return 0;
}
