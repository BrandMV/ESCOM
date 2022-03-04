#!/bin/bash

gcc ordenamientoPorMezcla.c tiempo.c -o ordenamientoPorMezcla
./ordenamientoPorMezcla 100 < numeros10millones.txt > ordenamientoPorMezcla.txt
./ordenamientoPorMezcla 1000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 5000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 10000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 50000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 100000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 200000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 400000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 600000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 800000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 1000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 2000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 3000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 4000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 5000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 6000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 7000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 8000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 9000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt
# ./ordenamientoPorMezcla 10000000 < numeros10millones.txt >> ordenamientoPorMezcla.txt


exit