cmake_minimum_required(VERSION 3.17)
project(happy_matrix)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2")
    else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(happy_matrix__1 src/main.cpp)
target_compile_definitions(happy_matrix__1 PRIVATE MAJOR_NUM=1 MINOR_NUM=1)
add_executable(happy_matrix__2_1 src/main.cpp)
target_compile_definitions(happy_matrix__2_1 PRIVATE MAJOR_NUM=2 MINOR_NUM=2)
add_executable(happy_matrix__2_2 src/main.cpp)
target_compile_definitions(happy_matrix__2_2 PRIVATE MAJOR_NUM=2 MINOR_NUM=3)
add_executable(happy_matrix__3_1 src/main.cpp)
target_compile_definitions(happy_matrix__3_1 PRIVATE MAJOR_NUM=3 MINOR_NUM=2)
add_executable(happy_matrix__3_2 src/main.cpp)
target_compile_definitions(happy_matrix__3_2 PRIVATE MAJOR_NUM=3 MINOR_NUM=3)
