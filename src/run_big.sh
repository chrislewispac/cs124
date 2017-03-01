#!/bin/bash
exec &>> ../output/big.txt

./rndmst 0 8192 5 1
./rndmst 0 8192 5 2
./rndmst 0 8192 5 3
./rndmst 0 8192 5 4

./rndmst 0 16384 5 1
./rndmst 0 16384 5 2
./rndmst 0 16384 5 3
./rndmst 0 16384 5 4
