#include <stdio.h>

void escribeNum();


void escribeNum(){
	int numeros[10], i;
	FILE * ptr; //puntero de tipo archivo
	
	ptr=fopen("numeros.txt", "w+"); //w+ crea un archivo de lectura y escritura
	
	if(ptr==NULL){
		printf("El archivo no se creo correctamente\n"); //si no se puede abrir o crear el archivo se sale del programa
		return;
	}
	
	for(i=0; i<10;i++){
		printf("Ingresa un numero: \n");
		scanf("%d", &numeros[i]); //leemos lus numeros ingresados por el usuario
		fprintf(ptr, "%d ",numeros[i]); //Se van guardando los números en el archivo
		
	}
	printf("Datos guardados");
	fclose(ptr); //Cerramos el archivo
}

int main(){
	
	escribeNum();
	return 0;

	
}
