#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100

typedef char stackEntry;

typedef struct stack{
	int top;
	stackEntry entry[MAXSTACK];
}Stack;

void push(stackEntry item, Stack *s);
stackEntry pop(Stack *s);
int stackEmpty(Stack *s);
int stackFull(Stack *s);
void createStack(Stack *s);
void topePila(Stack *s);
int orden(char s);
void infijaPos(char infi[], char pos[],Stack *s);
int operador(char s);


int main(int argc, char *argv[]) {
	
	Stack pila;
	int res=1;
	createStack(&pila);
	char infija[100], posfija [100];
	
	while(res==1)
	{
	printf("\nIngresar expresion? 1=si / 0=no: ");
	scanf("%d",&res);
	if(res==1)
	{
		printf("Ingresa tu expresion en notacion infija: ");
		scanf("%s",&infija);
		infijaPos(infija, posfija, &pila);
		printf("\nLa expresion en notacion posfija es: ");
		printf("%s",posfija);
	}
	else
		return 0;
	
	}

}

void infijaPos(char infi[], char pos[],Stack *s)
{
	int i=0, j=0;
	char item;
	char x;
	
	push('(',s);
	strcat(infi,")");
	
	item=infi[i];
	
	while(item!='\0')
	{
		if(item=='(')
			push(item,s);
		else
			if(isdigit(item) || isalpha(item))
			{
				pos[j]=item;
				j++;
			}
		else
			if(operador(item)==1)
			{
				x=pop(s);
				while(operador(x)==1 && orden(x)>=orden(item))
				{
					pos[j]==x;
					j++;
					x=pop(s);
				}
				push(x,s);
				push(item,s);
			}
		else
			if(item==')')
			{
				x=pop(s);
				while(x!='(')
				{
					pos[j]=x;
					j++;
					x=pop(s);
				}
			}
		else
			printf("La expresion infija esta mal escrita");
			
		i++;
		item=infi[i];
	}
	pos[j]='\0';
	
}

int orden(char s)
{
	if(s=='^')
		return(3);
	else 
		if(s=='*' || s=='/')
			return(2);
	else 
		if(s=='+' || s=='-') 
			return(1);
	else
		return(0);
}

int operador(char s)
{
	if(s=='^' || s=='*' || s=='/' || s=='+' || s=='-')
		return 1;
	else
		return 0;
}

void push(stackEntry item, Stack *s)
{
	if(stackFull(s))
		printf("\nError, la pila esta llena\n");
	else{
		s->entry[s->top++]=item;
		
	}
	
}

stackEntry pop( Stack *s)
{
	stackEntry item;
	if(stackEmpty(s))
		printf("\nError, la pila esta vacia\n");
		
	else{
		item=s->entry[--(s->top)];
		return item;
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
	
	z=pop(s);
	printf("El tope es: %c\n",z);
	push(z,s);	
	 
}
