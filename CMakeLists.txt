cmake_minimum_required(VERSION 3.17)
project(PasswordGuard)

set(CMAKE_CXX_STANDARD 17)

add_executable(PasswordGuard main.cpp core-func.h core-func.cpp peripheral-func.h peripheral-func.cpp)