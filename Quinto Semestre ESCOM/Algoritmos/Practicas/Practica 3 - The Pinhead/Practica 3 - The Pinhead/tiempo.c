
//*****************************************************************
//TIEMPO.C
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
//Librerias incluidas
//*****************************************************************
#include <sys/resource.h>
#include <sys/time.h>
#include "tiempo.h"

//*****************************************************************
//uswtime (Definici�n)
//*****************************************************************
//Descripci�n: Funci�n que almacena en las variables referenciadas 
//el tiempo de CPU, de E/S y Total actual del proceso actual.
//
//Recibe: Variables de tipo doble para almacenar los tiempos actuales
//Devuelve: 
//*****************************************************************#include <stdio.h>
void uswtime(double *usertime, double *systime, double *walltime)
{
	double mega = 1.0e-6;
	struct rusage buffer;
	struct timeval tp;
	struct timezone tzp;
	getrusage(RUSAGE_SELF, &buffer);
	gettimeofday(&tp, &tzp);
	*usertime = (double) buffer.ru_utime.tv_sec +1.0e-6 * buffer.ru_utime.tv_usec;
	*systime  = (double) buffer.ru_stime.tv_sec +1.0e-6 * buffer.ru_stime.tv_usec;
	*walltime = (double) tp.tv_sec + 1.0e-6 * tp.tv_usec; 
}

/*En Unix, se dispone de temporizadores ejecutables (en concreto time) que nos proporcionan medidas de los tiempos
de ejecuci�n de programas. Estos temporizadores nos proporcionan tres medidas de tiempo:
    * real:  Tiempo real que se ha tardado desde que se lanz� el programa a ejecutarse hasta que el programa finaliz� y proporcion� los resultados.
    * user: Tiempo que la CPU se ha dedicado exclusivamente a la computaci�n del programa.
    * sys: 	Tiempo que la CPU se ha dedicado a dar servicio al sistema operativo por necesidades del programa (por ejemplo para llamadas al sistema para efectuar I/O).
El tiempo real tambi�n suele recibir el nombre de elapsed time o wall time. Algunos temporizadores tambi�n proporcionan el porcentaje de tiempo que la CPU se ha dedicado al programa. Este porcentaje viene dado por la relaci�n entre el tiempo de CPU (user + sys)
y el tiempo real, y da una idea de lo cargado que se hallaba el sistema en el momento de la ejecuci�n del programa.
El grave inconveniente de los temporizadores ejecutables es que no son capaces de proporcionar medidas de tiempo de ejecuci�n de segmentos de c�digo. Para ello, hemos de invocar en nuestros propios programas  a un conjunto de temporizadores disponibles en la mayor parte de las librer�as de C de Unix, que ser�n los que nos proporcionen medidas sobre los tiempos de ejecuci�n de trozos discretos de c�digo.
En nuestras pr�cticas vamos a emplear una funci�n que act�e de temporizador y que nos proporcione los tiempos de CPU (user, sys)
y el tiempo real. En concreto, vamos a emplear el procedimiento uswtime listado a continuaci�n. 
Este procedimiento en realidad invoca a dos funciones de Unix: getrusage y gettimeofday. La primera de ellas nos proporciona el tiempo de CPU, tanto de usuario como de sistema, mientras que la segunda nos proporciona el tiempo real (wall time). Estas dos funciones son las que disponen de mayor resoluci�n de todos los temporizadores disponibles en Unix.
 
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
