#!/bin/bash
gcc busquedaBinariaHilos.c tiempo.c -lpthread -o busquedaBinariaHilos
echo Numero de Hilos: 2
./busquedaBinariaHilos 2 1000000 < numeros10millones.txt > busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 2000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 3000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 4000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 5000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 6000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 7000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 8000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 9000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 2 10000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
echo Numero de Hilos: 5
./busquedaBinariaHilos 5 1000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 2000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 3000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 4000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 5000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 6000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 7000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 8000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 9000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 5 10000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
echo Numero de Hilos: 10
./busquedaBinariaHilos 10 1000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 2000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 3000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 4000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 5000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 6000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 7000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 8000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 9000000 < numeros10millones.txt >> busquedaBinariaHilos.txt
./busquedaBinariaHilos 10 10000000 < numeros10millones.txt >> busquedaBinariaHilos.txt


exit
