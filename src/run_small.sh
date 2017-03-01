#!/bin/bash
exec &>> ../output/small.txt

./rndmst 0 128 5 1
./rndmst 0 128 5 2
./rndmst 0 128 5 3
./rndmst 0 128 5 4

./rndmst 0 256 5 1
./rndmst 0 256 5 2
./rndmst 0 256 5 3
./rndmst 0 256 5 4

./rndmst 0 512 5 1
./rndmst 0 512 5 2
./rndmst 0 512 5 3
./rndmst 0 512 5 4

./rndmst 0 1024 5 1
./rndmst 0 1024 5 2
./rndmst 0 1024 5 3
./rndmst 0 1024 5 4

./rndmst 0 2048 5 1
./rndmst 0 2048 5 2
./rndmst 0 2048 5 3
./rndmst 0 2048 5 4

./rndmst 0 4096 5 1
./rndmst 0 4096 5 2
./rndmst 0 4096 5 3
./rndmst 0 4096 5 4
