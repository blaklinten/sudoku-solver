#include <stdlib.h>
#include "sudoku.h"
#include "utils.h"

bool is_solved(Sudoku *s){
  for( int i = 0; i < GROUP_SIZE; i++){
    Sudoku_group *row = get_row_for_index(i * GROUP_SIZE, s);
    if (!is_solved_group(row))
      return false;
    Sudoku_group *column = get_column_for_index(i, s);
    if (!is_solved_group(column))
      return false;
    Sudoku_group *box = get_box_for_index(i, s);
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

Sudoku_group *get_row_for_index(int index, Sudoku *s) {
  int start_index = (index / GROUP_SIZE) * GROUP_SIZE;
  Sudoku_group *row = calloc(1, sizeof(Sudoku_group));
  for (int i = 0; i < GROUP_SIZE; i++) {
    (*row)[i] = (*s)[start_index + i];
  }
  return row;
}

Sudoku_group *get_column_for_index(int index, Sudoku *s) {
  int column_number = index % GROUP_SIZE;
  Sudoku_group *column = calloc(1, sizeof(Sudoku_group));
  for (int i = 0; i < GROUP_SIZE; i++) {
    (*column)[i] = (*s)[column_number + GROUP_SIZE * i];
  }
  return column;
}

Sudoku_group *get_box_for_index(int index, Sudoku *s) {
  int start_row = index / GROUP_SIZE / BOX_SIZE * BOX_SIZE;
  int start_column = index % GROUP_SIZE / BOX_SIZE * BOX_SIZE;
  int start_index = start_row * GROUP_SIZE + start_column;
  Sudoku_group *box = calloc(1, sizeof(Sudoku_group));
  for (int i = 0; i < BOX_SIZE; i++) {
    for (int j = 0; j < BOX_SIZE; j++){
      (*box)[i*BOX_SIZE + j] = (*s)[start_index + (i * GROUP_SIZE) + j];
    }
  }
  return box;
}

bool groups_equals(Sudoku_group *first, Sudoku_group *second) {
  for (int i = 0; i < GROUP_SIZE; i++) {
    if ((*first)[i] != (*second)[i]) {
      s_log(ERROR, __func__, "Groups differ at locaion %d; %d != %d", i,
            (*first)[i], (*second)[i]);
      return false;
    }
  }
  return true;
}

bool is_valid_position_for_number(int sudoku_number, Sudoku *s, int position_index){
  int assert_mask = 1 << sudoku_number;

  int row_mask = 0;
  Sudoku_group *row = get_row_for_index(position_index, s);
  for (int i = 0; i < GROUP_SIZE; i++) {
    row_mask = row_mask | 1 << (*row)[i];
  };
  if(row_mask & assert_mask){
    return false;
  }

  int column_mask = 0;
  Sudoku_group *column = get_column_for_index(position_index, s);
  for (int i = 0; i < GROUP_SIZE; i++) {
    column_mask = column_mask | 1 << (*column)[i];
  };
  if(column_mask & assert_mask){
    return false;
  }

  int box_mask = 0;
  for (int i = 0; i < GROUP_SIZE; i++) {
  Sudoku_group *box = get_box_for_index(position_index, s);
    box_mask = box_mask | 1 << (*box)[i];
  };
  if(box_mask & assert_mask){
    return false;
  }

  return true;
}
