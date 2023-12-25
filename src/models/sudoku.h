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
Sudoku_group *get_row_for_index(int, Sudoku *);
Sudoku_group *get_column_for_index(int, Sudoku *);
Sudoku_group *get_box_for_index(int, Sudoku *);
bool groups_equals(Sudoku_group *, Sudoku_group *);
bool is_valid_position_for_number(int, Sudoku *, int);

#endif // !SUDOKU
