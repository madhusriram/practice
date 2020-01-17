#!/bin/bash
# This script runs inside the container

mkdir build && cd build
cmake ../
make
./printBST
cd ../ && rm -rf build
