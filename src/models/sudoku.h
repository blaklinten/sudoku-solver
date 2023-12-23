#ifndef SUDOKU
#define SUDOKU

#include <stdbool.h>

#define GROUP_SIZE 9
#define SUDOKU_SIZE GROUP_SIZE *GROUP_SIZE
#define BOX_SIZE 3

typedef int Sudoku_group[GROUP_SIZE];
typedef int Sudoku[SUDOKU_SIZE];

bool is_solved_group(Sudoku_group *);
bool is_solved(Sudoku *);
Sudoku_group *get_row(int, Sudoku *);
Sudoku_group *get_column(int, Sudoku *);
Sudoku_group *get_box(int, Sudoku *);

#endif // !SUDOKU
