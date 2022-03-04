#include <stdio.h>
#include <stdlib.h>


typedef char stackEntry;

typedef struct node{
	stackEntry entry;
	struct node *next;
}Node;

typedef struct stack{
	Node *top;
}Stack;

Node *makeNode(stackEntry item);
void push(stackEntry item, Stack *s);
stackEntry pop( Stack *s);
int stackEmpty(Stack *s);
void createStack(Stack *s);
void topePila(Stack *s);

int main(int argc, char *argv[]) 
{
	int opc=0;
	Stack pila;
	stackEntry l;
	createStack(&pila);
	
	while(opc>=0)
	{
		printf("Operaciones con la pila:\n");
		printf("0. Saber si la pila esta vacia\n");
		printf("1. Insertar elemento a la pila\n");
		printf("2. Eliminar elemento de la pila\n");
		printf("3. Saber el tope de la pila\n");
		printf("4. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>5)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 0:
				system("cls");
				if(stackEmpty(&pila))
					printf("Puedes insertar mas elementos\n");
				else
					printf("Puedes insertar mas elementos\n");
				system("pause");
				system("cls");
				
				break;
			case 1:
				system("cls");
				printf("Ingrese una letra para agregar a la pila: ");
				scanf("%s",&l);
				push(l,&pila);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				pop(&pila);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");		
				if(stackEmpty(&pila))
					printf("Pila vacia\n");			
				else
					topePila(&pila);
						
				system("pause");
				system("cls");
				break;
			case 4:
				return 0;
		}
	}
	
	
	return 0;
}

void createStack(Stack *s)
{
	s->top=NULL;
}

Node *makeNode(stackEntry item)
{
	Node *nodePointer;
	
	if((nodePointer=(Node *)malloc(sizeof(Node)))==NULL)
		printf("Error, no se púede asignar la memoria");
	else{
		nodePointer->entry=item;
		nodePointer->next=NULL;
	}
	return nodePointer;
}

void push(stackEntry item, Stack *s)
{
	Node * np=makeNode(item);
	if(np==NULL)
		printf("Error, se intento ingresar un nodo que no existe");
	else{
		np->next=s->top;
		s->top=np;
	}
}

stackEntry pop(Stack *s)
{
	Node *curNode;
	stackEntry item;
	if(stackEmpty(s))
		printf("Pila vacia\n");
	else{
		curNode=s->top;
		item=s->top->entry;
		s->top=s->top->next;
		free(curNode);
		return item;
	}
}

int stackEmpty(Stack *s)
{
	return s->top==NULL;
}

void topePila(Stack *s)
{		
	stackEntry z;
	z=pop(s);
	printf("El tope es: %c\n",z);
	push(z,s);		 
}



