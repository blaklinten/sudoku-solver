cmake_minimum_required(VERSION 3.28.1)

project(sudoku_solver)

set(CMAKE_BUILD_TYPE Debug)

add_executable(sudoku_solver src/solver.c src/models/sudoku.c src/utils.c)
add_executable(sudoku_solver_test test/sudoku_test.c src/models/sudoku.c test/utils.c)


