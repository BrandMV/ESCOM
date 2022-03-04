#!/bin/bash

gcc burbujaOptimizada_2.c tiempo.c -o burbujaOptimizada_2
./burbujaOptimizada_2 100 < numeros10millones.txt > burbujaOptimizada_2.txt
./burbujaOptimizada_2 1000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 5000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 10000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 50000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 100000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 200000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 400000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 600000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 800000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 1000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 2000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 3000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 4000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 5000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 6000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 7000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 8000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 9000000 < numeros10millones.txt >> burbujaOptimizada_2.txt
# ./burbujaOptimizada_2 10000000 < numeros10millones.txt >> burbujaOptimizada_2.txt


exit