#!/bin/bash

gcc abb.c tiempo.c -o abb
./abb 100 < numeros10millones.txt >> abb.txt
./abb 1000 < numeros10millones.txt >> abb.txt
# ./abb 5000 < numeros10millones.txt >> abb.txt
# ./abb 10000 < numeros10millones.txt >> abb.txt
# ./abb 50000 < numeros10millones.txt >> abb.txt
# ./abb 100000 < numeros10millones.txt >> abb.txt
# ./abb 200000 < numeros10millones.txt >> abb.txt
# ./abb 400000 < numeros10millones.txt >> abb.txt
# ./abb 600000 < numeros10millones.txt >> abb.txt
# ./abb 800000 < numeros10millones.txt >> abb.txt
# ./abb 1000000 < numeros10millones.txt >> abb.txt
# ./abb 2000000 < numeros10millones.txt >> abb.txt
# ./abb 3000000 < numeros10millones.txt >> abb.txt
# ./abb 4000000 < numeros10millones.txt >> abb.txt
# ./abb 5000000 < numeros10millones.txt >> abb.txt
# ./abb 6000000 < numeros10millones.txt >> abb.txt
# ./abb 7000000 < numeros10millones.txt >> abb.txt
# ./abb 8000000 < numeros10millones.txt >> abb.txt
# ./abb 9000000 < numeros10millones.txt >> abb.txt
# ./abb 10000000 < numeros10millones.txt >> abb.txt

exit