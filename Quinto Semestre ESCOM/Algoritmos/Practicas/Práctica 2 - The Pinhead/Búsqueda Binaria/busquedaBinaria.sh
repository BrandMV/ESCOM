#!/bin/bash

gcc busquedaBinaria.c tiempo.c -o busquedaBinaria
./busquedaBinaria 1000000 < 10millones.txt > busquedaBinaria.txt
./busquedaBinaria 2000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 3000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 4000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 5000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 6000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 7000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 8000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 9000000 < 10millones.txt >> busquedaBinaria.txt
./busquedaBinaria 10000000 < 10millones.txt >> busquedaBinaria.txt

exit
