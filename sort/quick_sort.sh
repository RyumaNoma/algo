#!/bin/bash

gcc random.c -o random
./random 10000

cd quick_sort
g++ quick_sort.cpp -o quick_sort
time ./quick_sort

cd ..
g++ are_sorted.cpp -o are_sorted
./are_sorted