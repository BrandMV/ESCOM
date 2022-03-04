#include <stdio.h>
#include <stdlib.h>

#define VAL 5

int b_Binaria(int inf, int sup, int a[], int valor);
void quickSort(int arr[], int lI, int lD);

int main(int argc, char *argv[]) {
	
	int arr[VAL],i;
	int tam=sizeof(arr)/sizeof(int);
	int dato,inf,sup,pos,resp=1;
	
	printf("Ingrese elementos al arreglo: \n");
	for(i=0;i<tam;i++)
		scanf("%d",&arr[i]);
	
	quickSort(arr,0,tam-1);
	
	printf("\nLos elementos del arreglo son: ");
	for(i=0; i<tam;i++)
		printf("%d ",arr[i]);
	
	while(resp==1)
	{
		printf("\n¿Que numero quiere buscar? - ");
		scanf("%d",&dato);
		inf=0;
		sup=VAL;
	
		pos=b_Binaria(inf,sup,arr,dato);
		if(pos==-1)
			printf("\nEl numero no esta en el arreglo");
		else
			printf("\nEl numero %d esta en la posicion %d del arreglo", dato, pos+1);
		printf("\nBuscar otro numero? 1-si/0-no: ");
		scanf("%d",&resp);
		if(resp==0)
			return 0;
	}
	
		
	
	return 0;
}

int b_Binaria(int inf, int sup, int a[], int valor)
{
	int mitad;
	if(inf>sup)
		return -1;
	mitad=(inf+sup)/2;
	if(valor==a[mitad])
		return(mitad);
	if(valor<a[mitad])
		b_Binaria(inf,mitad-1,a,valor);
	else
		b_Binaria(mitad+1,sup,a,valor);
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
