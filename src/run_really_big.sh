#!/bin/bash
exec &>> ../output/really_really_big.txt

./rndmst 0 32768 2 1
./rndmst 0 32768 2 2
./rndmst 0 32768 2 3
./rndmst 0 32768 2 4

./rndmst 0 65536 2 1
./rndmst 0 65536 2 2
./rndmst 0 65536 2 3
./rndmst 0 65536 2 4
