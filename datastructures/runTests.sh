#!/bin/bash
# This script runs inside the container

mkdir build && cd build
cmake ../ 
make

# BST
./bst/printBST

# Linked list
./linkedlist/doublyCircularTests
./linkedlist/singlyListTests
./linkedlist/lruTest

cd ../ && rm -rf build
