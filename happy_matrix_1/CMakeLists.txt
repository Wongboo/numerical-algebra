cmake_minimum_required(VERSION 3.17)
project(happy_matrix)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2")
    else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(happy_matrix_1 src/main1.cpp)
add_executable(happy_matrix_2_1 src/main2_1.cpp)
add_executable(happy_matrix_2_2 src/main2_2.cpp)
add_executable(happy_matrix_3_1 src/main3_1.cpp)
add_executable(happy_matrix_3_2 src/main3_2.cpp)