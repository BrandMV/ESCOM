#!/bin/bash

gcc shell.c tiempo.c -o shell
./shell 100 < numeros10millones.txt >> shell.txt
./shell 1000 < numeros10millones.txt >> shell.txt
# ./shell 5000 < numeros10millones.txt >> shell.txt
# ./shell 10000 < numeros10millones.txt >> shell.txt
# ./shell 50000 < numeros10millones.txt >> shell.txt
# ./shell 100000 < numeros10millones.txt >> shell.txt
# ./shell 200000 < numeros10millones.txt >> shell.txt
# ./shell 400000 < numeros10millones.txt >> shell.txt
# ./shell 600000 < numeros10millones.txt >> shell.txt
# ./shell 800000 < numeros10millones.txt >> shell.txt
# ./shell 1000000 < numeros10millones.txt >> shell.txt
# ./shell 2000000 < numeros10millones.txt >> shell.txt
# ./shell 3000000 < numeros10millones.txt >> shell.txt
# ./shell 4000000 < numeros10millones.txt >> shell.txt
# ./shell 5000000 < numeros10millones.txt >> shell.txt
# ./shell 6000000 < numeros10millones.txt >> shell.txt
# ./shell 7000000 < numeros10millones.txt >> shell.txt
# ./shell 8000000 < numeros10millones.txt >> shell.txt
# ./shell 9000000 < numeros10millones.txt >> shell.txt
# ./shell 10000000 < numeros10millones.txt >> shell.txt


exit