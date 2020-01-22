cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link "tests" with what we want to test and the GTest and pthread library
add_executable(bstTests bstTest.cc)
target_link_libraries(bstTests ${GTEST_LIBRARIES} pthread)
