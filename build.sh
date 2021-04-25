#!/bin/bash

OPTS="-std=c++11"
SRCE="code/main.cpp code/core/*.cpp"

clang++ -o out $OPTS $SRCE
./out > image.ppm
