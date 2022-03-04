#include<stdio.h>
#include<limits.h>
 

 
void insert(int ary[],int hFn, int size){
    int element,pos,n=0, i;
 
 	for(i=1;i<=size;i++)
 	{
 		printf("Ingrese el numero\n");
		scanf("%d",&element);
 
	pos = element%hFn;
 
	while(ary[pos]!= INT_MIN) {  
		if(ary[pos]== INT_MAX)
            break;
		pos = (pos+1)%hFn;
		n++;
		if(n==size)
		break;     
	}
 
	if(n==size)
        printf("Tabla hash llena\n\n");
	else
        ary[pos] = element; 
	 }
	  
}
 
void del (int ary[],int hFn,int size){

	int element,n=0,pos;
 
	printf("Ingrese el elmento a eliminar\n");
	scanf("%d",&element);
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==INT_MIN){
			printf("Elemento no encontrado\n");
			break;
		}
		else if(ary[pos]==element){
			ary[pos]=INT_MAX;
			printf("Elementoi eliminado\n\n");
			break;
		}
		else{
			pos = (pos+1) % hFn;
		}
	}
	if(--n==size)
        printf("Elemento no encontrado en la tabla\n");
}
 
void search(int ary[],int hFn,int size){
	int element,pos,n=0;
 
	printf("Elemento a bucar\n");
	scanf("%d",&element);
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==element){
			printf("Elemento encontrado en el array %d\n",pos);
			break;
		}
		else
            if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
                pos = (pos+1) %hFn;
	}
	if(--n==size) printf("Elemento no encontrado el la tabla\n");
}
 
void display(int ary[],int size){
	int i;
 
	printf("array\tvalor\n");
 
	for(i=0;i<size;i++)

        printf("%d\t%d\n",i,ary[i]);
 
}
int main(){
	int size=10,hFn=10,i,choice;
 
	
 
	int ary[size];
 
	
	for(i=0;i<size;i++)
        ary[i]=INT_MIN;
	do{
	
		printf(" 1-> insertar\n 2-> eliminar\n 3-> imprimir\n 4-> buscar\n 0-> salir\n");
		scanf("%d",&choice);
 
		switch(choice){
			case 1:
				insert(ary,hFn,size);
				break;
			case 2:
				del(ary,hFn,size);
				break;
			case 3:
				display(ary,size);
				break;
			case 4:
				search(ary,hFn,size);
				break;
			default:
				printf("ingrese una opcion correcta\n");
				break;
		}
	}while(choice);
 
	return 0;
}
