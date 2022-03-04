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
int veri(char exp[],char abre, char cierra, Stack *s,int *i);


int main(int argc, char *argv[]) {
	
	int par=0,cor=0,llav=0;
	int i=0;
	Stack pila;
	createStack(&pila);
	char exp[100];
	printf("Ingrese una expresion para verificar si esta correcta o no: ");
	scanf("%s", &exp);
	
	if(veri(exp,'(',')',&pila,&i)==1)
		printf("\nParentesis correctos");
	if(veri(exp,'[',']',&pila,&i)==1)
		printf("\nCorchetes correctos");
	if(veri(exp,'{','}',&pila,&i)==1)
		printf("\nLLaves correctos");
	
	return 0;


}

int veri(char exp[],char abre, char cierra, Stack *s, int *i)
{
	stackEntry z;
	int x=0;
	int bal=1;
	*i=0;
	while(exp[x]!='\0' && bal==1)
	{
		bal=1;
		if(exp[x]==abre)
		{
			push(exp[x],s);
			bal=1;
		}
			
		else
			if(exp[x]==cierra)
				if(!stackEmpty(s))
						pop(&z,s);
				else
				{
					bal=0;
					printf("\nHay un elemento que cierra sin que haya uno que abra en: %d",*i);
				}
	
	
	
		x++;
		(*i)++;
	}
		
	if(bal==1 && !stackEmpty(s))
	{
		bal=0;
		printf("\nHay un elemento que abre sin que haya uno que cierre");
	}	
	
	while(!stackEmpty)
		pop(&z,s);
	return bal;
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
