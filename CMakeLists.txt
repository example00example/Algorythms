cmake_minimum_required(VERSION 3.2)
project(Algorythms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Algorythms ${SOURCE_FILES} Sortings/InsertionSort.h Sortings/InsertionSort.cpp Sortings/InsertionSort.h Sortings/InsertionSort.h Sortings/InsertionSort.cpp mystd.h LongArithmetics/LongInt.cpp LongArithmetics/LongInt.h Sortings/MergeSort.h Sortings/MergeSort.h)