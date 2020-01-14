#!/bin/bash
# This script runs inside the container

mkdir build && cd build
cmake ../
make
./runTests
cd ../ && rm -rf build
