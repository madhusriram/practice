#!/bin/bash
# This script runs inside the container

mkdir build && cd build
cmake ../
make
./doublyCircularTests
./singlyListTests
./lruTest
cd ../ && rm -rf build
