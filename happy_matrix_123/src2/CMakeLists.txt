add_executable(happy_matrix_2__1 main_1.cpp)
add_executable(happy_matrix_2__1_plus main_1.cpp)
add_executable(happy_matrix_2__1_quad main_1.cpp)
find_package(Boost)
if(${Boost_FOUND})
    target_include_directories(happy_matrix_2__1_plus PUBLIC ${Boost_INCLUDE_DIRS})
    target_compile_definitions(happy_matrix_2__1_plus PRIVATE USE_BOOST_RATIONAL)
    target_include_directories(happy_matrix_2__1_quad PUBLIC ${Boost_INCLUDE_DIRS})
    target_compile_definitions(happy_matrix_2__1_quad PRIVATE USE_BOOST_QUAD)
else()
    message("Boost not found, you cannot precisely calculate conditional number!")
endif()

#add_executable(happy_matrix_2__2 main_2.cpp)
add_executable(happy_matrix_2__2_plus main_2.cpp)
target_compile_definitions(happy_matrix_2__2_plus PRIVATE COUT_CONDITION_NUMBER)