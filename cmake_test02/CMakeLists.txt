CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(SIMPLE_CALCULATOR_MAIN)

include_directories(./src/include/)

aux_source_directory(./src SRC)

add_compile_options(-Wall -std=c++11 -o0)

set(EXECUTABLE_OUTPUT_PATH ./exe)
add_executable(simple_calcaltor_main ${SRC})