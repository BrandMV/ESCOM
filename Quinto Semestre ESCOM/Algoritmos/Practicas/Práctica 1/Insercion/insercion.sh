#!/bin/bash

gcc insercion.c tiempo.c -o insercion
./insercion 100 < numeros10millones.txt >> insercion.txt
./insercion 1000 < numeros10millones.txt >> insercion.txt
# ./insercion 5000 < numeros10millones.txt >> insercion.txt
# ./insercion 10000 < numeros10millones.txt >> insercion.txt
# ./insercion 50000 < numeros10millones.txt >> insercion.txt
# ./insercion 100000 < numeros10millones.txt >> insercion.txt
# ./insercion 200000 < numeros10millones.txt >> insercion.txt
# ./insercion 400000 < numeros10millones.txt >> insercion.txt
# ./insercion 600000 < numeros10millones.txt >> insercion.txt
# ./insercion 800000 < numeros10millones.txt >> insercion.txt
# ./insercion 1000000 < numeros10millones.txt >> insercion.txt
# ./insercion 2000000 < numeros10millones.txt >> insercion.txt
# ./insercion 3000000 < numeros10millones.txt >> insercion.txt
# ./insercion 4000000 < numeros10millones.txt >> insercion.txt
# ./insercion 5000000 < numeros10millones.txt >> insercion.txt
# ./insercion 6000000 < numeros10millones.txt >> insercion.txt
# ./insercion 7000000 < numeros10millones.txt >> insercion.txt
# ./insercion 8000000 < numeros10millones.txt >> insercion.txt
# ./insercion 9000000 < numeros10millones.txt >> insercion.txt
# ./insercion 10000000 < numeros10millones.txt >> insercion.txt

exit