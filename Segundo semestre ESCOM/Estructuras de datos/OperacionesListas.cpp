#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *head=NULL;

void insert(int num);
void add(int num);
void addAfter(int num, int loc);
int count();
void append(int num);
int del(int num);
void buscarPos(int num);
void buscarKaesimo(int num);
void display(struct node *r);

int main(int argc, char *argv[]) 
{
	int opc=0, aux=0;
	char r;
	int x;
	Node l1, l2;
	
	while(r!='f')
	{
		printf("Ingrese elementos de la primera lista; f para terminar: ");
		scanf("%d",&x);
		insert(x);
	}
	
	while(r!='f')
	{
		printf("Ingrese elementos de la segunda lista; f para terminar: ");
		scanf("%d",&x);
		insert(x);
	}
	
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

void insert(int num)
{
	int c=0;
	struct node *temp;
	temp=head;
	if(temp==NULL)
		add(num);
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<num)
				c++;
			temp=temp->next;
		}
		if(c==0)
			add(num);
		else if(c<count())
			addAfter(num,++c);
			else
				append(num);
	}
}

void add(int num)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

void addAfter(int num, int loc)
{
	int i=0;
	struct node *temp, *left, *right;
	right=head;
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

int count()
{
	struct node *n;
	int c=0;
	n=head;
	while(n!=NULL)
	{
		n=n->next;
		c++;
	}
	return c;
}

void append(int num)
{
	struct node *temp,*right;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	right=head;
	
	while(right->next!=NULL)
		right=right->next;
		
	right->next=temp;
	right=temp;
	right->next=NULL;
	
}

int del(int num)
{
	struct node *temp, *prev;
	temp=head;
	if(temp==NULL)
	{
		printf("Lista vacia\n");
		return;
	}
	
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==head)
			{
				head=temp->next;
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

void buscarPos(int num)
{
	int c=1;
	struct node *temp, *prev;
	temp=head;
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

void buscarKaesimo(int num)
{
	int c=1;
	struct node *temp, *prev;
	temp=head;
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
	

void display(struct node *r)
{
	r=head;
	if(r==NULL)
		printf("Lista vacia");
	while(r!=NULL)
	{
		printf("%d",r->data);
		r=r->next;
	}
	printf("\n");
}
