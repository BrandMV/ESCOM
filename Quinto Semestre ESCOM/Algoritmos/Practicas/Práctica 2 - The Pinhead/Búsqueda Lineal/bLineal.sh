#!/bin/bash

gcc bLineal.c tiempo.c -o bLineal
./bLineal 1000000 < numeros10millones.txt >> bLineal.txt
./bLineal 2000000 < numeros10millones.txt >> bLineal.txt
./bLineal 3000000 < numeros10millones.txt >> bLineal.txt
./bLineal 4000000 < numeros10millones.txt >> bLineal.txt
./bLineal 5000000 < numeros10millones.txt >> bLineal.txt
./bLineal 6000000 < numeros10millones.txt >> bLineal.txt
./bLineal 7000000 < numeros10millones.txt >> bLineal.txt
./bLineal 8000000 < numeros10millones.txt >> bLineal.txt
./bLineal 9000000 < numeros10millones.txt >> bLineal.txt
./bLineal 10000000 < numeros10millones.txt >> bLineal.txt

gcc hilosBLineal.c tiempo.c -lpthread -o hilosBLineal
./hilosBLineal 5 1000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 2000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 3000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 4000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 5000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 6000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 7000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 8000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 9000000 < numeros10millones.txt >> bLineal.txt
./hilosBLineal 5 10000000 < numeros10millones.txt >> bLineal.txt

exit