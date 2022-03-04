#include <stdio.h>
#include <math.h>

void leeNum();
void operaciones(int num[]);

void leeNum(){
	
	FILE * ptr; //puntero de tipo archivo
	int num[10], i;
	ptr= fopen("numeros.txt", "r"); //Abrimos el archivo del programa2 en modo lectura
	
	if(ptr==NULL){
		printf("El archivo no se abrio correctamente\n"); //si no se puede abrir o crear el archivo se sale del programa
		return;
	}
	
	for(i=0; i<10; i++){
		fscanf(ptr, "%d ", &num[i]); //leemos los datos del archivo
		printf("%d\n", num[i]);
	}
	fclose(ptr);
	
	operaciones(num); //llamamos a la funcion que hace las oepraciones
	
}

void operaciones(int num[]){

	float suma, mult, prom, desvEst, var, numf[10], desvi;
	int i=0;
	
	for(i=0; i<10; i++){
		numf[i]= (float)num[i]; //pasamos nuestro arreglo a flotantes para realizar las operaciones
		suma+=numf[i]; //hacemos la suma
		mult*=numf[i]; //hacemos la multiplicaciones
		desvi+= pow(numf[i] - (suma/10), 2); //calculamos las desviaciones necesarias para la varianza
	}
	prom=suma/10; //Calculamos el promedio
	var=desvi/9; //calculamos la varianza
	desvEst= sqrt(var); //calculamos la desviación estándar
	
	printf("El promedio es: %0.2f\nLa suma es: %0.2f\nLa multiplicacion es: %e\n", prom, suma, mult);
	printf("La desviacion estandar es: %0.2f\nLa varianza es: %0.2f", desvEst, var);
	
}

int main(){
	
	leeNum();
	
	return 0;
}
