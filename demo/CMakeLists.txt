cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(MY_EIGEN_DEMO)

set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3)
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

add_executable(basic_matrix_test basic_matrix.cpp)
add_executable(basic_poly_test basic_poly.cpp)
add_executable(basic_linear_solve_test basic_linear_solve.cpp)

