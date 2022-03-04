#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}Node;

Node *head=NULL;

void insert(int dato);
void del(int dato);
int find(Node *current, int dato);
void display(Node *current);

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
		printf("6. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>6)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Ingrese elemento: ");
				scanf("%d",&x);
				insert(x);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Ingrese elemento a eliminar: ");
				scanf("%d",&x);
				del(x);
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
				display(&r);
				system("pause");
				system("cls");
				break;	
			case 6:
				return 0;
		}
	}
	
	
	
	return 0;
}

void insert(int dato)
{
	Node *current=NULL;
	current=head;
	current->next=NULL;
	current->prev=NULL;
	while(current->next!=NULL)
		current=current->next;
	current->next=(Node *)malloc (sizeof(Node));
	(current->next)->prev=current;
	current=current->next;
	current->data=dato;
	current->next=NULL;
}

void del(int dato)
{
	Node *current=NULL;
	current=head;
	if(current==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
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

int find(Node *current, int dato)
{
	int c=1;
	current=current->next;
	while(current!=NULL)
	{
		if(current->data==dato)
		{
			printf("El elemento %d esta en la posicion %d",dato, c);
			return;
		}
		current=current->next;
		c++;
	}
	return;

}

void display(Node *current)
{
	current=head;
	if(current==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
	while(current!=NULL)
	{
		printf("%d",current->data);
		current=current->next;
	}
}
