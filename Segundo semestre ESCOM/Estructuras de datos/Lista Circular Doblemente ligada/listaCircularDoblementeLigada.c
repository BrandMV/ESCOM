#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}Node;

Node *primero=NULL;
Node *ultimo=NULL;


void insert();
void del(Node *current, int dato);
int find(Node *current, int dato);
void display();
void displayReversa();

int main(int argc, char *argv[])
{
	int opc=0, aux=0;
	int x;
	Node r;
	

	
	while(opc>=0)
	{
		printf("Operaciones con la lista:\n");
		printf("1. Insertar elemento a la lista\n");
		printf("2. Eliminar elemento de la lista\n");	
		printf("3. Buscar la posicion de un numero\n");
		printf("4. Buscar el elemento en cierta posicion\n");
		printf("5. Desplegar lista\n");
		printf("6. Desplegar lista desde el ultimo\n");
		printf("7. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>7)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				insert();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Ingrese elemento a eliminar: ");
				scanf("%d",&x);
				del(&head,x);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("Ingrese elemento para saber su posicion: ");
				scanf("%d",&x);
				//buscarPos(head,x);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				printf("Ingrese posicion para saber el numero: ");
				scanf("%d",&x);
			//	buscarKaesimo(x);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				display();
				system("pause");
				system("cls");
				break;	
			case 6:
				system("cls");
				displayReversa();
				system("pause");
				system("cls");
				break;	
			case 7:
				return 0;
		}
	}
	
	
	
	return 0;
}

void insert()
{
	Node *nuevo=(Node *) malloc(sizeof(Node));
	printf("Ingrese el dato a insertar: ");
	scanf("%d", &nuevo->data);
	
	if(primero==NULL)
	{
		primero=nuevo;
		primero->next=primero;
		ultimo=primero;
		primero->prev=ultimo;
	}
	else
	{
		ultimo->next=nuevo;
		nuevo->next=primero;
		nuevo->prev=ultimo;
		ultimo=nuevo;
		primero->prev=ultimo;
	}
	printf("\nInsertaste %d",nuevo->data);
}

void del(Node *current, int dato)
{
	while(current->next!=NULL && (current->next)->data!=dato)
		current=current->next;
	if(current->next==NULL)
	{
		printf("El elemento %d no se encuentra en la lista\n",dato);
		return;
	}
	Node *tmp=current->next;
	if(tmp->next==NULL)
		current->next=NULL;
	else
	{
		current->next=tmp->next;
		(current->next)->prev=tmp->prev;
	}
	free(tmp);
	return;
}

void find()
{
	Node *current=(Node *) malloc(sizeof(Node));
	current=primero;
	int busc=0, fo=0;
	printf("Ingrese el elemento a buscar: ");
	scanf("%d",&busc);
	
	if(primero!=NULL)
	{
		while(current!=NULL)
		{
			if(current->data==busc)
			{
				printf("\n")
			}
		}
	}

}

void display()
{
	Node *current=(Node *) malloc(sizeof(Node));
	current=primero;
	if(primero!=NULL)
	{
		do{
			printf("\n %d",current->data);
			current=current->next;
		}while(current!=primero);
	}
	else
	{
		printf("\Lista vacia");
	}
}

void displayReversa()
{
	Node *current=(Node *) malloc(sizeof(Node));
	current=ultimo;
	if(primero!=NULL)
	{
		do{
			printf("\n %d",current->data);
			current=current->prev;
		}while(current!=ultimo);
	}
	else
	{
		printf("\Lista vacia");
	}
}
