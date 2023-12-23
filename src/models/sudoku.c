#include <stdlib.h>
#include "sudoku.h"

bool is_solved(Sudoku *s){
  for( int i = 0; i < GROUP_SIZE; i++){
    Sudoku_group *row = get_row(i, s);
    if (!is_solved_group(row))
      return false;
    Sudoku_group *column = get_column(i, s);
    if (!is_solved_group(column))
      return false;
    Sudoku_group *box = get_box(i, s);
    if (!is_solved_group(box))
      return false;
  }
  return true;
}

bool is_solved_group(Sudoku_group *numbers) {
  int mask = 0;
  for (int i = 0; i < GROUP_SIZE; i++) {
    int current = (*numbers)[i];
    mask = mask | 1 << current;
  };
  if (mask != 1022) // 1111111110
    return false;
  return true;
}

Sudoku_group *get_row(int row_number, Sudoku *s) {
  Sudoku_group *row = calloc(1, sizeof(Sudoku_group));
  int start_index = row_number * GROUP_SIZE;
  for (int i = 0; i < GROUP_SIZE; i++) {
    (*row)[i] = (*s)[start_index + i];
  }
  return row;
}

Sudoku_group *get_column(int column_number, Sudoku *s) {
  Sudoku_group *column = calloc(1, sizeof(Sudoku_group));
  for (int i = 0; i < GROUP_SIZE; i++) {
    (*column)[i] = (*s)[column_number + GROUP_SIZE * i];
  }
  return column;
}

Sudoku_group *get_box(int box_number, Sudoku *s) {
  Sudoku_group *box = calloc(1, sizeof(Sudoku_group));
  int start_row = (box_number / BOX_SIZE) * BOX_SIZE;
  int start_column = (box_number % BOX_SIZE) * BOX_SIZE;
  int start_index = start_row * GROUP_SIZE + start_column;
  for (int i = 0; i < BOX_SIZE; i++) {
    for (int j = 0; j < BOX_SIZE; j++){
      (*box)[i*BOX_SIZE + j] = (*s)[start_index + (i * GROUP_SIZE) + j];
    }
  }
  return box;
}
