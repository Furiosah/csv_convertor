#!/bin/bash
gcc -c main.c convert_to_csv.c read_csv.c
gcc main.o convert_to_csv.o read_csv.o
./a.out

