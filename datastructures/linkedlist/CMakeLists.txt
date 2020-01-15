cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link "tests" with what we want to test and the GTest and pthread library
add_executable(doublyCircularTests doublyCircularListTest.cc)
add_executable(singlyListTests singlyListTest.cc)
target_link_libraries(doublyCircularTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(singlyListTests  ${GTEST_LIBRARIES} pthread)
