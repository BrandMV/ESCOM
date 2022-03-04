#!/bin/bash

gcc bubbleSort.c tiempo.c -o bubbleSort
./bubbleSort 100 < numeros10millones.txt >> bubbleSort.txt
./bubbleSort 1000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 5000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 10000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 50000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 100000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 200000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 400000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 600000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 800000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 1000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 2000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 3000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 4000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 5000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 6000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 7000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 8000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 9000000 < numeros10millones.txt >> bubbleSort.txt
# ./bubbleSort 10000000 < numeros10millones.txt >> bubbleSort.txt


exit