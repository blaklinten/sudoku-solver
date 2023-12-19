#include "sudoku.h"

bool assert_valid_sudoku_group(Sudoku_group numbers) {
  int mask = 0;
  for (int i = 0; i < SUDOKU_NUMBERS; i++) {
    int current = numbers[i];
    mask = mask | 1 << current;
  };
  if (mask != 1022) // 1111111110
    return false;
  return true;
}

Sudoku_group *get_row(int row_number, Sudoku s) {
  Sudoku_group *row = calloc(1, sizeof(Sudoku_group));
  int start_index = row_number * SUDOKU_NUMBERS;
  for (int i = 0; i < SUDOKU_NUMBERS; i++) {
    (*row)[i] = s[start_index + i];
  }
  return row;
}
