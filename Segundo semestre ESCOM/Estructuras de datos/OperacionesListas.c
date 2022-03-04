#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;



void insert(int num, struct node *l);
void add(int num, struct node *l);
void addAfter(int num, int loc, struct node *l);
int count(struct node *l);
void append(int num, struct node *l);
int del(int num, struct node *l);
void buscarPos(int num, struct node *l);
void buscarKaesimo(int num, struct node *l);
void display(struct node *r, struct node *l);
void crearLista(struct node *l);


int main(int argc, char *argv[]) 
{
	int opc=0, aux=0;
	int r=1,t=1;
	int x;
	Node l1, l2, g;
	
	crearLista(&l1);
	crearLista(&l2);
	while(r==1)
	{
		printf("Ingrese elementos de la primera lista:  ");
		scanf("%d",&x);
		insert(x,&l1);
		printf("\nIngresar datos? 0-no; 1-si: ");
		scanf("%d",&r);
	}
	
	while(t==1)
	{
		printf("Ingrese elementos de la segunda lista: ");
		scanf("%d",&x);
		insert(x,&l2);
		printf("\nIngresar datos? 0-no; 1-si: ");
		scanf("%d",&t);
	}
	display(&g,&l1);
	display(&g,&l2);
	
	
}

/*
lista_t *UnirListas (node *l1, node *l2){
   lista_t *p;
   if (l1 == NULL){  
      l1 = l2;
   }
   else{
        if (l2 != NULL){  
           p = l1;           
           while (p->sig != NULL)
              p = p->sig;
         
           p->sig = l2;        
        }
   }
   return l1;     
} */

void crearLista(struct node *l)
{
	l=NULL;
}

void insert(int num, struct node *l)
{
	int c=0;
	struct node *temp;
	temp=l;
	if(temp==NULL)
		add(num,l);
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<num)
				c++;
			temp=temp->next;
		}
		if(c==0)
			add(num,l);
		else if(c<count(l))
			addAfter(num,++c,l);
			else
				append(num,l);
	}
}

void add(int num, struct node *l)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	if(l=NULL)
	{
		l=temp;
		l->next=NULL;
	}
	else
	{
		temp->next=l;
		l=temp;
	}
}

void addAfter(int num, int loc, struct node *l)
{
	int i=0;
	struct node *temp, *left, *right;
	right=l;
	for(i=1;i<loc;i++)
	{
		left=right;
		right=right->next;
	}
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	left->next=temp;
	left=temp;
	left->next=right;
	return;
}

int count(struct node *l)
{
	struct node *n;
	int c=0;
	n=l;
	while(n!=NULL)
	{
		n=n->next;
		c++;
	}
	return c;
}

void append(int num, struct node *l)
{
	struct node *temp,*right;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	right=l;
	
	while(right->next!=NULL)
		right=right->next;
		
	right->next=temp;
	right=temp;
	right->next=NULL;
	
}

int del(int num, struct node *l)
{
	struct node *temp, *prev;
	temp=l;
	if(temp==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
	
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==l)
			{
				l=temp->next;
				free(temp);
				return 1;
			}
			else
			{
				prev->next=temp->next;
				free(temp);
				return 1;
			}
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	printf("Elemento no encontrado\n");
}

void buscarPos(int num, struct node *l)
{
	int c=1;
	struct node *temp, *prev;
	temp=l;
	if(temp==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
	while(temp!=NULL && temp->data!=num)
	{
		temp=temp->next;
		c++;
	}
	if(temp==NULL)
	{
		printf("No encontrado\n");
		return;
	}
	printf("el numero %d esta en la posicion %d\n",num,c);
		
}

void buscarKaesimo(int num, struct node *l)
{
	int c=1;
	struct node *temp, *prev;
	temp=l;
	if(temp==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
	while(temp!=NULL && c!=num)
	{
		temp=temp->next;
		c++;
		
	}
	if(temp==NULL)
	{
		printf("La lista solo tiene %d elementos\n",c-1);
		return;
	}
	printf("Elemento en la posicion %d es %d\n",num,temp->data);
		
}
	

void display(struct node *r, struct node *l)
{
	r=l;
	if(r==NULL)
		printf("Lista vacia");
	while(r!=NULL)
	{
		printf("%d",r->data);
		r=r->next;
	}
	printf("\n");
}
