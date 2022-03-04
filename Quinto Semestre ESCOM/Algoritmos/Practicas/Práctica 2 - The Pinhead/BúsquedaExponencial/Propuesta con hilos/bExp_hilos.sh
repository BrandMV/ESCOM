#!/bin/bash

gcc busquedaExpHilos.c tiempo.c -lpthread -o busquedaExpHilos
./busquedaExpHilos 1000000 < 10millones.txt > busquedaExpHilos.txt
./busquedaExpHilos 2000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 3000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 4000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 5000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 6000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 7000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 8000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 9000000 < 10millones.txt >> busquedaExpHilos.txt
./busquedaExpHilos 10000000 < 10millones.txt >> busquedaExpHilos.txt

exit
