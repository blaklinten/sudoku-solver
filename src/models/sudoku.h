#ifndef SUDOKU
#define SUDOKU

#include <stdbool.h>
#include <stdlib.h>

#define SUDOKU_NUMBERS 9
#define SUDOKU_SIZE SUDOKU_NUMBERS *SUDOKU_NUMBERS

typedef int Sudoku_group[SUDOKU_NUMBERS];
typedef int Sudoku[SUDOKU_SIZE];

bool assert_valid_sudoku_group(Sudoku_group);
Sudoku_group *get_row(int, Sudoku);

#endif // !SUDOKU
