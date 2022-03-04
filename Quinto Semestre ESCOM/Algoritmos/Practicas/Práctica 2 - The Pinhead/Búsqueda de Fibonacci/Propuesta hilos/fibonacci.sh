#!/bin/bash

gcc fibonacci.c tiempo.c -o fibonacci -lpthread
./fibonacci 1000000 1 < 10millones.txt >> fibonacci.txt
./fibonacci 2000000 2 < 10millones.txt >> fibonacci.txt
./fibonacci 3000000 3 < 10millones.txt >> fibonacci.txt
./fibonacci 4000000 4 < 10millones.txt >> fibonacci.txt
./fibonacci 5000000 5 < 10millones.txt >> fibonacci.txt
./fibonacci 6000000 6 < 10millones.txt >> fibonacci.txt
./fibonacci 7000000 7 < 10millones.txt >> fibonacci.txt
./fibonacci 8000000 8 < 10millones.txt >> fibonacci.txt
./fibonacci 9000000 9 < 10millones.txt >> fibonacci.txt
./fibonacci 10000000 10 < 10millones.txt >> fibonacci.txt

exit