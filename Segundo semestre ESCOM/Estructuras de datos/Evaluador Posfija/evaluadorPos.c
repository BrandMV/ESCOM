#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSTACK 100

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
void evaluarPos(char posfija[], Stack *s);
void imprimir(Stack *s);


int main(int argc, char *argv[]) 
{
	int i=0,res=1;
	char posfija[100];
	Stack pila;
	createStack(&pila);
	printf("Evaluador de notacion posfija, solo se permiten numeros de 1 cifra,\npara indicar el final de su expresion ingrese una f; 6523+8*+3+*f\n");
	while(res==1)
	{
	printf("\nIngresar expresion? 1=si / 0=no: ");
	scanf("%d",&res);
	if(res==1)
	{
	printf("\nIngrese su expresion en la forma posfija: ");
	
	for(i=0;i<=100-1;i++)
	{
		scanf("%c", &posfija[i]);
		if(posfija[i]=='f')
			break;
	}
	evaluarPos(posfija,&pila);
	}
	else
		return 0;
	
	}
}

void evaluarPos(char posfija[], Stack *s)
{
	int i=0;
	char c;
	int res=0,a=0,b=0;
	
	for(i=0;posfija[i]!='f';i++)
	{

		c=posfija[i];

		if(isdigit(c))
			push(c-'0',s);
		else
			if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
			{
				pop(&a,s);
				pop(&b,s);
				
				switch(c)
				{
					case '^':
						res=pow(b,a);
						break;
					case '*':
						res=b*a;
						break;
					case '/':
						res=b/a;
						break;
					case '+':
						res=b+a;
						break;
					case '-':
						res=b-a;
						break;
						
				}
				
				push(res,s);
			}
	}	
	
	
	pop(&res,s);
	printf("El resultado de la expresion es: %d", res);		
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
