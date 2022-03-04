#include <stdio.h>
#include <stdlib.h>

#define VAL 5

void print(int v[], int tam);
void quickSort(int v[], int izq, int der);

int main(int argc, char *argv[]) {
	
	int arr[VAL],i;
	int tam=sizeof(arr)/sizeof(int);
	int der=0;
	
	printf("Ingrese elementos al arreglo: \n");
	for(i=0;i<tam;i++)
		scanf("%d",&arr[i]);
		
	printf("Elementos desordenados \n");
	for(i=0; i<tam;i++)
		printf("%d \t",arr[i]);
		
	quickSort(arr,0,tam-1);
	
	printf("\nElementos ordenados \n");
	for(i=0; i<tam;i++)
		printf("%d \t",arr[i]);
	
	return 0;
}


void quickSort(int arr[], int lI, int lD) {
	int temp,pivote;
	int izq=lI;
	int der=lD;
	
	pivote=arr[(izq+der)/2];
	
	do{
		while(arr[izq]<pivote && izq<lD)
			izq++;
		while(pivote<arr[der] && der>lI)
			der--;
		if(izq<=der)
		{
			temp=arr[izq];
			arr[izq]=arr[der];
			arr[der]=temp;
			izq++;
			der--;
		}
	}while(izq<=der);
	if(lI<der)
		quickSort(arr,lI,der);
	if(lD>izq)
		quickSort(arr,izq,lD);
}

void print(int v[], int tam)
{
	int i=0;
	for(i=0; i<tam;i++)
		printf("%d",v[i]);
			if(i<tam-1)
				printf(",");
}
