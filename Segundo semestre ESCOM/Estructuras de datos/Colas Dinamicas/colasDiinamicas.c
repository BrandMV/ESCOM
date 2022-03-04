#include <stdio.h>
#include <stdlib.h>

typedef int queueEntry;

typedef struct node{
	queueEntry data;
	struct node *next;
}Node;

Node *front=NULL;
Node *rear=NULL;

void enqueue(queueEntry x);
void dequeue(void);
queueEntry Front(void);
void print(void);

int main(int argc, char *argv[]) 
{
	int opc=0, aux=0;
	queueEntry x;
	
	while(opc>=0)
	{
		printf("Operaciones con la pila:\n");
		printf("1. Insertar elemento a la cola\n");
		printf("2. Eliminar elemento de la cola\n");
		printf("3. Desplegar cola\n");
		printf("4. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>3)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Ingrese elemento: ");
				sncaf("%d",&x);
				enqueue(x);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				delete();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				display();
				system("pause");
				system("cls");
				break;			
			case 4:
				return 0;
		}
	}


}

void enqueue(queueEntry x)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

void dequeue(void)
{
	Node *temp=front;
	if(front==NULL)
	{
		printf("La cola esta vacia\n");
		return;
	}
	
	if(front==rear)
		front=rear=NULL;
	else
		front=front->next;
	free(temp);
}

queueEntry Front(void)
{
	if(front==NULL)
	{
		printf("La cola esta vacia\n");
		return;
	}
	return front->data;
}

void print(void)
{
	Node *temp=front;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


