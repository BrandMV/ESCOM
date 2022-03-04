#!/bin/bash

gcc ABBIterativo.c tiempo.c -o ABBIterativo
./ABBIterativo 1000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 2000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 3000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 4000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 5000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 6000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 7000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 8000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 9000000 < numeros10millones.txt >> ABBIterativo.txt
./ABBIterativo 10000000 < numeros10millones.txt >> ABBIterativo.txt

exit