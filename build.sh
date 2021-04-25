#!/bin/bash

OPTS="-std=c++11"
SRCE="*.cpp"

clang++ -o out.o $OPTS $SRCE
./out.o > image.ppm
