#include <stdio.h>
#include <stdlib.h>


struct nodo{
	int dato;
	struct nodo *der;
	struct nodo *izq;
};

typedef struct nodo _nodo;

_nodo *crear(int dato);
_nodo *addDerecha(_nodo *nuevo, _nodo *raiz);
_nodo *addIquierda(_nodo *nuevo, _nodo *raiz);
void imprimirPre(struct nodo *reco);
void imprimir(_nodo *nodo);

int main(int argc, char *argv[]) 
{
	
	int opc=0, aux=0, x=0;

	
	while(opc>=0)
	{
		printf("Operaciones con el arbol binario:\n");
		printf("1. Insertar elemento\n");
		printf("2. Eliminar elemento\n");
		printf("3. Imprimir en preorden\n");
		printf("4. Mostrar el frente de la cola\n");
		printf("5. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>5)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Ingrese elemento: ");
				scanf("%d",&x);
				insertar(x);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				eliminar(raiz);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				imprimirPre(raiz);
				system("pause");
				system("cls");
				break;	
			case 4:
				system("cls");	
				//printf("El frente es: %d\n",Front());
				system("pause");
				system("cls");	
				break;
			case 5:
				return 0;
		}
	}

	
	return 0;
}

_nodo *crear(int dato)
{
	//se crea una hoja del arbol vacia
	_nodo *nuevo;
	
	nuevo= (_nodo *)malloc(sizeof(_nodo));
	nuevo->dato=dato;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	
	return nuevo;
}

_nodo *addDerecha(_nodo *nuevo, _nodo *raiz)
{
	raiz->der=nuevo;
	return raiz;
		
}

_nodo *addIquierda(_nodo *nuevo, _nodo *raiz)
{
	raiz->izq=nuevo;
	return raiz;
		
}

void imprimir(_nodo *nodo)
{
	if(nodo != NULL)
		printf(" %d ", nodo->dato);
	 
}


void imprimirPre(_nodo *raiz) //raiz izquierda derecha
{
	if(raiz!=NULL)
	{
		imprimir(raiz);
		imprimirPre(raiz->izq);
		imprimirPre(raiz->der);
	}
}



