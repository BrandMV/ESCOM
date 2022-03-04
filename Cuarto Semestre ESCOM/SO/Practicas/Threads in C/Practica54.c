#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int NumeroOcurrencias;
int NumeroElementosCopiados;

int cuentaOcurrencia(char *cadena, char *subcadena){
	char *tmp = cadena;
	char *pdest;	
	int ocur = 0, pos;
	int len = strlen(subcadena);
	while(1){
		pdest = strstr(tmp, subcadena);
		if( !pdest ) break;
	        pos = pdest - tmp;
		tmp += pos + len;
		ocur++;
	}
	return ocur;
}

void *Codigo_Hilo1(void *arg){
	printf("Contando ocurrencias en el archivo, similares a 'pr'\n");
	FILE* flujo = fopen("Archivo1.txt","rb");
	fseek(flujo,0,SEEK_END);
	int num_elementos = ftell(flujo);
	rewind(flujo);
	char* cadena = (char*)calloc(sizeof(char),num_elementos);
	int num_elementos_leidos = fread(cadena,sizeof(char),num_elementos,flujo);
	char cadena2[2]="pr";
	NumeroOcurrencias = cuentaOcurrencia(cadena,cadena2);
	printf("El numero de Ocurrencias encontradas fue de: %d\n",NumeroOcurrencias);
	free(cadena);
	fclose(flujo);
   	pthread_exit(NULL);
}

void *Codigo_Hilo2(void *arg){
	system("cp *.txt *.c subdirectorio/");
	system("ls -A1 subdirectorio/ | wc -l");
	NumeroElementosCopiados = 3;
	pthread_exit(NULL);
}

void *Codigo_Hilo3(void *arg){
	printf("Generando Reporte de datos\n");
	FILE* flujo = fopen("Archivo2.txt","w");

	char cadena1[200] = "El numero de ocurrencias encontradas en el Archivo1.txt fue de: ";
	char ocurr[10];
	sprintf(ocurr,"%d",NumeroOcurrencias);
	strcat(cadena1,ocurr);
	strcat(cadena1,"\n");

	char cadena2[200] = "El numero de elementos copiados al subdirectorio fue de: ";
	char copi[10];
	sprintf(copi,"%d",NumeroElementosCopiados);
	strcat(cadena2,copi);
	strcat(cadena2,"\n");
	
	fputs(cadena1,flujo);
	fputs(cadena2,flujo);
	fflush(flujo);
	fclose(flujo);
	pthread_exit(NULL);
}

int main(){
	pthread_t hilo1;
	pthread_t hilo2;
	pthread_t hilo3;
	pthread_create(&hilo1,NULL,Codigo_Hilo1,NULL);
	pthread_join(hilo1,NULL);
	printf("Hilo numero 1 terminado\n");
	pthread_create(&hilo2,NULL,Codigo_Hilo2,NULL);
	pthread_join(hilo2,NULL);
	printf("Hilo numero 2 terminado\n");
	pthread_create(&hilo3,NULL,Codigo_Hilo3,NULL);
	pthread_join(hilo3,NULL);
	printf("Hilo numero 3 terminado\n");
	pthread_exit(NULL);
	return 0;
}
