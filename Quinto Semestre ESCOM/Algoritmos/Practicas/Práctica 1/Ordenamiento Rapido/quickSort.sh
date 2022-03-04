#!/bin/bash

gcc quickSort.c tiempo.c -o quickSort
./quickSort 100 < numeros10millones.txt >> quickSort.txt
./quickSort 1000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 5000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 10000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 50000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 100000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 200000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 400000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 600000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 800000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 1000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 2000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 3000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 4000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 5000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 6000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 7000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 8000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 9000000 < numeros10millones.txt >> quickSort.txt
# ./quickSort 10000000 < numeros10millones.txt >> quickSort.txt


exit