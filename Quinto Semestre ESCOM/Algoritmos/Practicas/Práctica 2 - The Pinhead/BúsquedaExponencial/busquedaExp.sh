#!/bin/bash

gcc busquedaExp.c tiempo.c -o busquedaExp
./busquedaExp 1000000 < 10millones.txt > busquedaExp.txt
./busquedaExp 2000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 3000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 4000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 5000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 6000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 7000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 8000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 9000000 < 10millones.txt >> busquedaExp.txt
./busquedaExp 10000000 < 10millones.txt >> busquedaExp.txt

exit
