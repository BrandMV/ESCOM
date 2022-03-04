#!/bin/bash

gcc burbujaMejorada.c tiempo.c -o burbujaMejorada
./burbujaMejorada 100 < numeros10millones.txt >> burbujaMejorada.txt
./burbujaMejorada 1000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 5000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 10000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 50000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 100000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 200000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 400000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 600000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 800000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 1000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 2000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 3000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 4000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 5000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 6000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 7000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 8000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 9000000 < numeros10millones.txt >> burbujaMejorada.txt
# ./burbujaMejorada 10000000 < numeros10millones.txt >> burbujaMejorada.txt


exit