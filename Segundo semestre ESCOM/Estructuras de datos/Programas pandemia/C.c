#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;


void insert(int num);
void add(int num);
void addafter(int num, int loc);
int count();
void addend(int num);
void display(struct node *r);
int dd(int num);
int buscarElemento(int num, int cont);
void MoverAlFrente(struct node *temp);

int main(int argc, char *argv[]) 
{
	int n,x;
	int cont=0,nr=0;
	struct node *d;
	int opc;
	while(opc>=0)
	{
		printf("LISTA LINEAL SIMPLEMENTE ENLAZADA\n\n");
		printf("1. Insertar elemento a la lista\n");
		printf("2. Eliminar elemento de la lista\n");
		printf("3. Buscar elemento en la lista\n");
		printf("4. Imprimir la lista\n");
		printf("5. Salir\n");
		printf("\nQue desea realizar?: ");
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1:
				printf("\nIngrese un numero: ");
				scanf("%d", &n);
				insert(n);
				system("pause");
				system("cls");
				break;
			case 2:
				printf("\nIngrese elemento a eliminar: ");
				scanf("%d",&n);
				dd(n);
				system("pause");
				system("cls");
				break;
			case 3:
				printf("Ingrese el elemento a buscar: ");
				scanf("%d", &n);
				if(n!=nr)
				{
					cont=0;
					nr=n;
				}
				else
					cont++;	
			
				x=buscarElemento(n,cont);
				if(x!=0)
					printf("El elemento %d esta en la lista en la posicion %d\n",n,x);
				else
					printf("El elemento %d no esta en la lista\n",n);
				
				system("pause");
				system("cls");
				break;
			case 4:
				printf("\nLista: \n");
				display(d);
					
				system("pause");
				system("cls");
				break;	
			case 5:
				return 0;
				break;
		}
	}
	
	return 0;
}

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
				addafter(num,++c);
			 else
			 	addend(num);
	}			
}

void add(int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
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

void addafter(int num, int loc)
{
	int i;
	struct node *temp, *left, *right;
	right=head;
	
	for(i=1;i<loc;i++)
	{
		left=right;
		right=right->next;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	left->next=temp;
	left=temp;
	left->next=right;
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

void addend(int num)
{
	struct node *temp, *right;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	right=head;
	while(right->next!=NULL)
		right=right->next;
	right->next=temp;
	right=temp;
	right->next=NULL;
}

void display(struct node *r)
{
	r=head;
	if(r==NULL)
		printf("Lista vacia");
		
	while(r!=NULL)
	{
		printf("%d ", r->data);
		r=r->next;
	}
	printf("\n");
}

int dd(int num)
{
	struct node *temp, *prev;
	temp=head;
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
	return 0;
}

int buscarElemento(int num, int cont)
{
	struct node *temp, *prev, *aux;
	int x=1;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{	
			if(temp==head)
			{
				return x;
			}
			else if(cont==3)
			{
				prev->next=temp->next;
				temp->next=head;
				head=temp;
			}
			else
			{
				if(head==prev)
				{
					head=temp;
					prev->next=temp->next;
					temp->next=prev;
				}
				else
				{
				aux->next=temp;
				prev->next=temp->next;
				temp->next=prev;
				}
			}
			return x;
		}
		else
		{
			aux=prev;
			prev=temp;
			temp=temp->next;
		}
		x++;
	}
	return 0;
}



