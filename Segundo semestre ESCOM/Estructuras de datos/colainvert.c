#include <stdio.h>
#include <stdlib.h>

typedef int queueEntry;

typedef struct node{
	queueEntry data;
	struct node *next;
}Node;

Node *pila;


typedef struct cola{
	Node *front;
	Node *rear;
}Cola;


void enqueue(Cola *c,queueEntry x);
void dequeue(Cola *c);
void print(Cola *c);
void invertirCola(Cola c, Node *s);
void concatenar(Cola c1,Cola c2, Cola c3);
void push(Node *pila, int n);

int main(int argc, char *argv[]) 
{
	int opc=0, aux=0,c=0;
	queueEntry x;
	Cola c1,c2,c3;
	c1.front=NULL, c1.front=NULL, c2.front=NULL, c2.front=NULL, c3.front=NULL, c3.front=NULL;
	Node pila;
	
	while(opc>=0)
	{
		printf("Operaciones con la pila:\n");
		printf("1. Insertar elemento a la cola\n");
		printf("2. Eliminar elemento de la cola\n");
		printf("3. Desplegar cola\n");
		printf("4. Mostrar el frente de la cola\n");
		printf("5. Invertir cola\n");
		printf("6. Concatenar dos colas\n");
		printf("7. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>7)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 1:
				system("cls");
				printf("A que cola lo quiere ingresar? 1 0 2: ");
				scanf("%d",&c);
				printf("Ingrese elemento: ");
				scanf("%d",&x);
				if(c==1)
					enqueue(&c1,x);
				else
					enqueue(&c2,x);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("De que cola quiere eliminar? 1 0 2: ");
				scanf("%d",&c);
				if(c==1)
					dequeue(&c1);
				else
					dequeue(&c2);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("Que cola quiere imprimir? 1 0 2: ");
				scanf("%d",&c);
				if(c==1)
					print(&c1);
				else
					print(&c2);
				system("pause");
				system("cls");
				break;	
			case 4:
				system("cls");	
			//	printf("El frente es: %d\n",Front());
				system("pause");
				system("cls");	
				break;
			case 5:
				system("cls");	
				printf("Cola invertida:\n");
				printf("Que cola queire invertir? 1 0 2: ");
				scanf("%d",&c);
				if(c==1)
					invertirCola(c1,&pila);
				else
					invertirCola(c2,&pila);
				system("pause");
				system("cls");	
				break;
			case 6:
				return 0;
		}
	}


}

void push(Node *pila, int n)
{
	Node *nd;
	nd=(Node *)malloc(sizeof(Node));
	if(nd!=NULL)
	{
		nd->data=n;
		nd->next=pila;
		pila=nd;
	}
}

void concatenar(Cola c1,Cola c2, Cola c3)
{
	Node *n1, *n2, *n3;
	
	n1=c1.rear;
	n2=c2.rear;
	while(n1!=NULL)
	{
		enqueue(&c3,n1->data);
		n1=n1->next;
	}
	while(n2!=NULL)
	{
		enqueue(&c3,n2->data);
		n2=n2->next;
	}
	n1=c3.rear;
	while(n1!=NULL)
	{
		printf("dato: %d",n1->data);
		n1=n1->next;
	}
		
}
void enqueue(Cola *c, queueEntry x)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	
	if(c->front==NULL && c->rear==NULL)
	{
		c->front=c->rear=temp;
		return;
	}
	(c->rear)->next=temp;
	c->rear=temp;
}

void dequeue(Cola *c)
{
	Node *temp=c->front;
	if(c->front==NULL)
	{
		printf("La cola esta vacia\n");
		return;
	}
	
	if(c->front==c->rear)
		c->front=c->rear=NULL;
	else
		c->front=(c->front)->next;
	printf("Eliminaste %d\n",temp->data);
	free(temp);
}


void print(Cola *c)
{
	Node *temp=c->front;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void invertirCola(Cola c, Node *s)
{
	Node *n1;
	n1=c.rear;
	while(c.rear!=NULL)
	{
		n1=c.rear;
		push(&s,n1->data);
		c.rear=n1->next;
		free(n1);
	}
	c.rear=NULL;
	c.front=NULL;
	while(s!=NULL)
	{
		enqueue(&c,s->data);
		s=s->next;
	}
	n1=c.rear;
	while(n1!=NULL)
	{
		printf("Datos: %d",n1->data);
		n1=n1->next;
	}
}
