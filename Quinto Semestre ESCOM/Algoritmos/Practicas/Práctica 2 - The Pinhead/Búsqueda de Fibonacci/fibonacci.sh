#!/bin/bash

gcc fibonacci.c tiempo.c -o fibonacci
./fibonacci 1000000 < 10millones.txt >> fibonacci.txt
./fibonacci 2000000 < 10millones.txt >> fibonacci.txt
./fibonacci 3000000 < 10millones.txt >> fibonacci.txt
./fibonacci 4000000 < 10millones.txt >> fibonacci.txt
./fibonacci 5000000 < 10millones.txt >> fibonacci.txt
./fibonacci 6000000 < 10millones.txt >> fibonacci.txt
./fibonacci 7000000 < 10millones.txt >> fibonacci.txt
./fibonacci 8000000 < 10millones.txt >> fibonacci.txt
./fibonacci 9000000 < 10millones.txt >> fibonacci.txt
./fibonacci 10000000 < 10millones.txt >> fibonacci.txt

exit