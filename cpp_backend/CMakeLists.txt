cmake_minimum_required(VERSION 3.15)
project(cpp_backend)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_backend main.cpp utils.cpp utils.h record.cpp record.h global.h)