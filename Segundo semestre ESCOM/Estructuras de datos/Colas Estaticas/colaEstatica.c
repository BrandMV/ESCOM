#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert(void);
void delete(void);
void display(void);

int queue[MAX], front=-1, rear=-1;

int main(int argc, char *argv[]) 
{
	int opc=0, aux=0;
	
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
				insert();
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

	return 0;
}

void insert(void)
{
	int num;
	printf("Ingrese el dato:\n");
	scanf("%d",&num);
	if(front==0 && rear==MAX-1)
		printf("Cola llena\n");
	else
		if(front==-1 && rear==-1)
		{
			front=rear=0;
			queue[rear]=num;
		}
		else
			if(rear==MAX-1 && front!=0)
			{
				rear=0;
				queue[rear]=num;
			}
			else
			{
				rear++;
				queue[rear]=num;
			}
}

void delete(void)
{
	int element;
	if(front==-1)
		printf("No hay elementos\n");
	element=queue[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
		
	}
	printf("Elemento eliminado: %d\n",element);
}

void display(void)
{
	int i;
	for(i=front;i<=rear;i++)
		printf("%d\n",queue[i]);
}
