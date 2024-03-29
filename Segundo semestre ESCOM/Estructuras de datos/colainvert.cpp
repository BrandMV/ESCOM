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
void invertirCola(void);

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
		printf("4. Mostrar el frente de la cola\n");
		printf("5. Invertir cola\n");
		printf("6. Salir\n");
		printf("�Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>6)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Ingrese elemento: ");
				scanf("%d",&x);
				enqueue(x);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				dequeue();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				print();
				system("pause");
				system("cls");
				break;	
			case 4:
				system("cls");	
				printf("El frente es: %d\n",Front());
				system("pause");
				system("cls");	
				break;
			case 5:
				system("cls");	
				printf("Cola invertida:\n");
				invertirCola();
				system("pause");
				system("cls");	
				break;
			case 6:
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
	printf("Eliminaste %d\n",temp->data);
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

void invertirCola(void)
{
	Node *temp;
	front=NULL;
	rear=NULL;
	while(temp!=NULL)
	{
		enqueue(temp->data);
		temp=temp->next;
	}
	Node *t=rear;
	while(t!=NULL)
	{
		printf("Datos: %d",t->data);
		t=t->next;
	}
}
