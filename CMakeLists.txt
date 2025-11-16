cmake_minimum_required(VERSION 4.0)
project(A3b)

set(CMAKE_CXX_STANDARD 20)

add_executable(A3b
        SortTester/SortTester.cpp
        SortTester/SortTester.h
        ArrayGenerator/ArrayGenerator.cpp
        ArrayGenerator/ArrayGenerator.h
        Sorter/Sorter.cpp
        Sorter/Sorter.h
        tests.cpp)
