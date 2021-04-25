#!/bin/bash

OPTS="-std=c++11"
SRCE="*.cpp"

clang++ -o out $OPTS $SRCE
./out > image.ppm
