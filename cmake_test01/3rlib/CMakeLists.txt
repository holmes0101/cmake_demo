CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(Calculator)

set(CMAKE_SYSTEM_NAME Linux)
include_directories(./src)
aux_source_directory(./src SRC)
add_compile_options(-Wall -std=c++11 -o2)

set(LIBRARY_OUTPUT_PATH ./lib/x86)

add_library(simpleCalculator SHARED ${SRC})

