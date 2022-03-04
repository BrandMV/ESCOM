#!/bin/bash

gcc hilosABB.c tiempo.c -lpthread -o hilosABB
./hilosABB 10 1000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 2000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 3000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 4000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 5000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 6000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 7000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 8000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 9000000 < numeros10millones.txt >> ABBIterativoHilos.txt
./hilosABB 10 10000000 < numeros10millones.txt >> ABBIterativoHilos.txt

exit