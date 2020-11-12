cmake_minimum_required(VERSION 3.17)
project(happy_matrix)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")
find_package(OpenMP REQUIRED)
link_libraries(OpenMP::OpenMP_CXX)

add_subdirectory(src1)
add_subdirectory(src2)
#add_subdirectory(src3)
add_executable(test test.cpp)


