﻿cmake_minimum_required(VERSION 2.8)
project(matrix)
add_library(matlib src/interval.h src/stopwatch.h src/myexception.h src/matrix.h src/matrix.cpp)
add_executable(matexe MACOSX_BUNDLE src/main.cpp)
target_link_libraries(matexe matlib)