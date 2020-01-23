cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add debug flag 
add_compile_options("-g") 

# Link "tests" with what we want to test and the GTest and pthread library
add_subdirectory(bst)
add_subdirectory(linkedlist)
