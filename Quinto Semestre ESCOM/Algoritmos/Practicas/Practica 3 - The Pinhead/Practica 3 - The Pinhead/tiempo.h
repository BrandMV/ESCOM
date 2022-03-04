
//*****************************************************************
//TIEMPO.H 
//*****************************************************************
//*****************************************************************
//M. EN C. EDGARDO ADRI�N FRANCO MART�NEZ 
//Curso: An�lisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medici�n de tiempo en C y recepci�n de parametros en C bajo UNIX
//Compilaci�n de la libreria: "gcc -c tiempo.c " (Generaci�n del c�digo objeto)
//*****************************************************************


//*****************************************************************
//uswtime (Declaraci�n)
//*****************************************************************
//Descripci�n: Funci�n que almacena en las variables referenciadas 
//el tiempo de CPU, de E/S y Total actual del proceso actual.
//
//Recibe: Variables de tipo doble para almacenar los tiempos actuales
//Devuelve: 
//*****************************************************************
void uswtime(double *usertime, double *systime, double *walltime);
/* 
Modo de Empleo:
La funci�n uswtime se puede emplear para medir los tiempos de ejecuci�n de determinados segmentos de c�digo en nuestros programas. De forma esquem�tica, el empleo de esta funci�n constar�a de los siguientes pasos:
    1.- Invocar a uswtime para fijar el instante a partir del cual se va a medir el tiempo.
            uswtime(&utime0, &stime0, &wtime0);
    2.- Ejecutar el c�digo cuyo tiempo de ejecuci�n se desea medir.
    3.- Invocar a uswtime para establecer el instante en el cual finaliza la medici�n
        del tiempo de ejecuci�n.
            uswtime(&utime1, &stime1, &wtime1);
    4.- Calcular los tiempos de ejecuci�n como la diferencia entre la primera y segunda
        invocaci�n a uswtime:
            real:   wtime1 - wtime0
            user:   utime1 - utime0
            sys :   stime1 - stime0
            El porcentaje de tiempo dedicado a la ejecuci�n de ese segmento de c�digo
            vendr�a dado por la relaci�n CPU/Wall:
	CPU/Wall = (user + sys) / real x 100 %*/
