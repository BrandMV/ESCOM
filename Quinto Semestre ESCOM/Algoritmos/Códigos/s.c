#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int NUMBER, i, s;
	double time_spent;
    clock_t begin, end;
	
	NUMBER = atoi(argv[1]); 	//Capturar el número de iteraciones que se desean realizar
	
	begin = clock();			//Tomar el reloj en este punto
	
    //*************************************************************
	for (s = i = 0; i < NUMBER; ++i) 
	{
        s ++;
    }
	//*************************************************************
	
	end = clock();				//Tomar el reloj en este punto
	
	time_spent = (double)(end - begin)/ CLOCKS_PER_SEC; 	//Saber el número de segundos trascurridos
    
	printf("\nSe realizaron %d iteraciones e incrementos de s en %.10f segundos",s,time_spent);
	
	return 0;
}
