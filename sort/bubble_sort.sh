#!/bin/bash

gcc random.c -o random
./random 10000

cd bubble_sort
g++ bubble_sort.cpp -o bubble_sort
time ./bubble_sort

cd ..
g++ are_sorted.cpp -o are_sorted
./are_sorted