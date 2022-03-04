#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef char StackEntry;
typedef struct node{
	StackEntry entry;
	struct node * next;
}Node;

typedef struct stack{
	Node *top;
}Stack;

void CreateStack(Stack *s);
Node *MakeNode(StackEntry item);
void push(StackEntry item, Stack *s);
StackEntry pop(Stack *s);
int StackEmpty(Stack *s);
StackEntry TopePila(Stack *s);
void infijaPos(char infi[], char pos[], Stack *p);
int orden(char s);

int main(int argc, char *argv[]) {
	
	Stack p;
	CreateStack(&p);

	int res=1;

	char infija[100], posfija [100];

		printf("Ingresa tu expresion en notacion infija: ");
		gets(infija);
		infijaPos(infija, posfija,&p);
		printf("\nLa expresion en notacion posfija es: ");
		puts(posfija);
	
	return 0;

}

void infijaPos(char infi[], char pos[], Stack *p)
{
	int i=0, j=0;
	char item;
	char x;
	
	while(infi[i]!='\0')
	{
		if(infi[i]>= 'a' && infi[i]<= 'z' || infi[i]>='A' && infi[i]<= 'Z')
		{
			pos[i]=infi[i];
			i++;
			j++;
		}
		else
			if(infi[i]=='(')
			{
				push(infi[i], p);
				i++;
			}
		else
			if(infi[i]==')')
			{
				while((TopePila(p)) != '(')
				{
					pos[j]=pop(p);
					j++;
				}
					if(TopePila(p) == '(')
						x=pop(p);
					i++;
			}
			else
				if(infi[i]=='+' || infi[i]=='-' || infi[i]=='*' || infi[i]=='/' || infi[i]=='^')
				{
					if(infi[i]=='+' || infi[i]=='-')
					{
						while(!StackEmpty(p) && TopePila(p) !='(')
						{
							pos[j]=pop(p);
							j++;
						}
						push(infi[i],p);
						i++;
					}
					else
					{
						if(infi[i]=='*' || infi[i]=='/')
						{
								while(!StackEmpty(p) && TopePila(p) !='(' && (TopePila(p)=='*' || TopePila(p)=='/'))
								{
									pos[j]=pop(p);
									j++;
								}
								push(infi[i],p);
								i++;
						}
						else
						{
								if(infi[i]=='^')
								{
									while(!StackEmpty(p) && TopePila(p) !='(' && (TopePila(p)=='^'))
									{
										pos[j]=pop(p);
										j++;
									}
									push(infi[i],p);
									i++;
								}
						}
					}
			
				
				}
				else
				{
					printf("\nNo valido");
					infi[i]='\0';
				}
		
	}
	while(!StackEmpty(p))
	{
		pos[j]=pop(p);
		j++;
	}
	pos[j]='\0';
	
}

int orden(char s)
{
	if(s=="(" || s==")")
 		return(4);
	if(s=='^')
		return(3);
	if(s=='*' || s=='/')
		return(2);
	if(s=='+' || s=='-') 
		return(1);
	return 0;

}

int operador(char s)
{
	if(s=='^' || s=='*' || s=='/' || s=='+' || s=='-')
		return 1;
	else
		return 0;
}

void CreateStack(Stack *s)
{
	s->top=0; 
}

Node *MakeNode(StackEntry item)
{
	Node *nodepointer;
	if((nodepointer = (Node *)malloc(sizeof(Node)))==NULL)
		printf("Error, no se pudo asignari la memoria");
	else
	{
		nodepointer->entry=item;
		nodepointer->next=NULL;	
	}
	return nodepointer;
}

void push(StackEntry item, Stack *s)
{
	Node *np = MakeNode(item);
	
	if(np==NULL)
		printf("Error, se intento ingresar un nodo que no existe");
	else
	{
		np->next=s->top;
		s->top=np;	
	}
}

StackEntry pop(Stack *s)
{
	Node *CurNode;
	StackEntry item;
	
	if(StackEmpty(s))
		printf("Pila vacia.");
	else
	{
		CurNode=s->top;
		item=s->top->entry;
		s->top=s->top->next;
		free(CurNode);
		
		return item;	
	}
}

int StackEmpty(Stack *s)
{
	return s->top==NULL;
}

StackEntry TopePila(Stack *s)
{
	StackEntry le;
	
	le=pop(s);
	push(le,s);
	return(le);
	
}
