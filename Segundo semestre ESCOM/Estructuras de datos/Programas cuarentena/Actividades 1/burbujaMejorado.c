#include <stdio.h>
#include <stdlib.h>

#define VAL 5

void swap(int *a, int *b);
void bubbleSort(int v[], int n);
void bubbleSortAs(int arr[], int n);
void bubbleSortDes(int arr[], int n);

int main(int argc, char *argv[]) {
	
	int opc=0;
	int arr[VAL],i;
	int tam=sizeof(arr)/sizeof(int);
	int der=0;
	
	printf("Ingrese elementos al arreglo: \n");
	for(i=0;i<tam;i++)
		scanf("%d",&arr[i]);
	
	while(opc>=0)
	{
		printf("¿Como quiere ordenar?:\n");
		printf("1. Ascendente\n");
		printf("2. Descendente\n");
		printf("3. salir\n");
		printf("¿Que desea realizar?: ");
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Elementos desordenados \n");
				for(i=0; i<tam;i++)
					printf("%d \t",arr[i]);
				bubbleSortAs(arr,tam);
				printf("\nElementos ordenados \n");
				for(i=0; i<tam;i++)
					printf("%d \t",arr[i]);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Elementos desordenados \n");
				for(i=0; i<tam;i++)
					printf("%d \t",arr[i]);
				bubbleSortDes(arr,tam);
				printf("\nElementos ordenados \n");
				for(i=0; i<tam;i++)
					printf("%d \t",arr[i]);
				system("pause");
				system("cls");
				break;
			case 3:
				return 0;
		}
	}

		
	
		
	
	
	
	
	
	return 0;
}

void bubbleSortAs(int arr[], int n)
{
	int i=0, j=0,k=0, aux;
	
	for(i=0;i<n-1;i++)
	{
		aux=0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				aux=1;
			}
		}
		
		for(k=n-2-i;k>i;k--)
			if(arr[k]<arr[k-1])
			{
				swap(&arr[k],&arr[k-1]);
				aux=1;
			}
		
		if(aux==0)
			break;
	}
}

void bubbleSortDes(int arr[], int n)
{
	int i=0, j=0,k=0, aux;
	
	for(i=0;i<n-1;i++)
	{
		aux=0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				aux=1;
			}
		}
		
		for(k=n-2-i;k>i;k--)
			if(arr[k]>arr[k-1])
			{
				swap(&arr[k],&arr[k-1]);
				aux=1;
			}
		
		if(aux==0)
			break;
	}
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
