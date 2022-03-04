#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 5

typedef char stackEntry;

typedef struct stack{
	int top;
	stackEntry entry[MAXSTACK];
}Stack;

void push(stackEntry item, Stack *s);
void pop(stackEntry *item, Stack *s);
int stackEmpty(Stack *s);
int stackFull(Stack *s);
void createStack(Stack *s);
void topePila(Stack *s);
void imprimir(Stack *s);


int main(int argc, char *argv[]) {
	
	int opc=0, aux=0;
	stackEntry l;
	stackEntry t;
	Stack pila;
	createStack(&pila);
	
	while(opc>=0)
	{
		printf("Operaciones con la pila:\n");
		printf("0. Saber si la pila esta llena\n");
		printf("1. Saber si la pila esta vacia\n");
		printf("2. Insertar elemento a la pila\n");
		printf("3. Eliminar elemento de la pila\n");
		printf("4. Saber el tope de la pila\n");
	//	printf("5. Enlistar elementos\n");
		printf("5. Salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		if(opc>6)
			printf("Opcion no valida");
			
		switch(opc)
		{
			case 0:
				system("cls");
				aux=stackFull(&pila);
			//	printf("%d\n",aux);
				if(aux==0)
					printf("Puedes insertar mas elementos\n");
				else
					printf("Pila llena\n");
				system("pause");
				system("cls");
				
				break;
			case 1:
				system("cls");
				aux=stackEmpty(&pila);
			//	printf("%d\n",aux);
				if(aux==1)
					printf("La pila esta vacia\n");
				else
					printf("La pila no esta vacia\n");
				
				system("pause");
				system("cls");
				break;
			
			case 2:
				system("cls");
				printf("Ingrese una letra para agreagar a la pila: ");
				scanf("%s",&l);
				push(l,&pila);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				pop(&l, &pila);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				
				if(stackEmpty(&pila))
					printf("Pila vacia\n");	
					
				else
					topePila(&pila);
					
				system("pause");
				system("cls");
				break;
			/*
			case 5:
				system("cls");
				imprimir(&pila);
				system("pause");
				system("cls");
				break;
				*/
			case 5:
				return 0;
		}
	}

}

void push(stackEntry item, Stack *s)
{
	if(stackFull(s))
		printf("\nError, la pila esta llena\n");
	else{
		s->entry[s->top++]=item;
		
	}
	
}

void pop(stackEntry *item, Stack *s)
{
	if(stackEmpty(s))
		printf("\nError, la pila esta vacia\n");
		
	else{
		*item=s->entry[--(s->top)];
		
	}
		
}

int stackEmpty(Stack *s)
{
	return s->top<=0;
}

int stackFull(Stack *s)
{
	return s->top>=MAXSTACK; 
}

void createStack(Stack *s)
{
	s->top=0; 
}

void topePila(Stack *s)
{		
	stackEntry z;
	
	pop(&z,s);
	printf("El tope es: %c\n",z);
	push(z,s);	
	 
}

/*
void imprimir(Stack *s)
{
	int i=0;
	if(!stackEmpty(s))
		for(i=s->top;i>=0;i--)
			printf("%c\n",s->entry[i]);
	else
		printf("Pila vacia\n");
}
*/

