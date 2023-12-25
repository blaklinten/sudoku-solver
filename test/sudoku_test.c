#include <stdlib.h>

#include "../src/models/sudoku.h"
#include "../src/utils.h"

Sudoku solved =     {1, 2, 3, 4, 5, 6, 7, 8, 9,
                     4, 5, 6, 7, 8, 9, 1, 2, 3,
                     7, 8, 9, 1, 2, 3, 4, 5, 6,
                     2, 3, 4, 5, 6, 7, 8, 9, 1,
                     5, 6, 7, 8, 9, 1, 2, 3, 4,
                     8, 9, 1, 2, 3, 4, 5, 6, 7,
                     3, 4, 5, 6, 7, 8, 9, 1, 2,
                     6, 7, 8, 9, 1, 2, 3, 4, 5,
                     9, 1, 2, 3, 4, 5, 6, 7, 8};

Sudoku unsolved =   {1, 2, 3, 4, 5, 6, 7, 8, 9,
                     4, 5, 6, 7, 8, 9, 1, 2, 3,
                     7, 8, 9, 1, 2, 3, 4, 5, 6,
                     5, 6, 7, 5, 6, 7, 8, 9, 1,
                     2, 3, 4, 8, 9, 1, 2, 3, 4,
                     8, 9, 1, 2, 3, 4, 5, 6, 7,
                     3, 4, 5, 6, 7, 8, 9, 1, 2,
                     6, 7, 8, 9, 1, 2, 3, 4, 5,
                     9, 1, 2, 3, 4, 5, 6, 7, 8};

Sudoku unfinished = {0, 0, 0, 0, 0, 2, 1, 5, 7,
                     0, 0, 0, 3, 0, 0, 8, 6, 0,
                     1, 4, 0, 0, 8, 0, 0, 0, 0,
                     0, 0, 0, 0, 5, 4, 0, 2, 6,
                     0, 0, 0, 0, 0, 0 ,0, 0, 0,
                     0, 9, 6, 0, 0, 7, 0, 0, 0,
                     6, 5, 0, 0, 2, 3, 0, 0, 0,
                     9, 0, 0, 0, 0, 0, 0, 0, 3,
                     8, 7, 0, 0, 0, 0, 0, 9, 0};

bool test_get_row() {
  s_log(INFO, __func__, "Running");
  Sudoku_group expected0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Sudoku_group expected1 = {4, 5, 6, 7, 8, 9, 1, 2, 3};
  Sudoku_group expected2 = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  Sudoku_group expected3 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
  Sudoku_group expected4 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  Sudoku_group expected5 = {8, 9, 1, 2, 3, 4, 5, 6, 7};
  Sudoku_group expected6 = {3, 4, 5, 6, 7, 8, 9, 1, 2};
  Sudoku_group expected7 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
  Sudoku_group expected8 = {9, 1, 2, 3, 4, 5, 6, 7, 8};

  Sudoku_group *expected[GROUP_SIZE] = {&expected0, &expected1, &expected2,
                                        &expected3, &expected4, &expected5,
                                        &expected6, &expected7, &expected8};

  for(int i = 0; i < GROUP_SIZE; i++){
    for(int j = 0; j < GROUP_SIZE; j++){
      Sudoku_group *row = get_row_for_index(i * GROUP_SIZE + j, &solved);
      if(!groups_equals(row, expected[i])){
        s_log(ERROR, __func__, "Failed");
        return false;
      }
    }
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_column() {
  s_log(INFO, __func__, "Running");
  Sudoku_group expected0 = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  Sudoku_group expected1 = {2, 5, 8, 3, 6, 9, 4, 7, 1};
  Sudoku_group expected2 = {3, 6, 9, 4, 7, 1, 5, 8, 2};
  Sudoku_group expected3 = {4, 7, 1, 5, 8, 2, 6, 9, 3};
  Sudoku_group expected4 = {5, 8, 2, 6, 9, 3, 7, 1, 4};
  Sudoku_group expected5 = {6, 9, 3, 7, 1, 4, 8, 2, 5};
  Sudoku_group expected6 = {7, 1, 4, 8, 2, 5, 9, 3, 6};
  Sudoku_group expected7 = {8, 2, 5, 9, 3, 6, 1, 4, 7};
  Sudoku_group expected8 = {9, 3, 6, 1, 4, 7, 2, 5, 8};

  Sudoku_group *expected[GROUP_SIZE] = {&expected0, &expected1, &expected2,
                                        &expected3, &expected4, &expected5,
                                        &expected6, &expected7, &expected8};
  for(int i = 0; i < GROUP_SIZE; i++){
    for(int j = 0; j < GROUP_SIZE; j++){
      Sudoku_group *column = get_column_for_index(i * GROUP_SIZE + j, &solved);
      if(!groups_equals(column, expected[j])){
        s_log(ERROR, __func__, "Failed");
        return false;
      }
    }
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_box() {
  s_log(INFO, __func__, "Running");
  Sudoku_group expected0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Sudoku_group expected1 = {4, 5, 6, 7, 8, 9, 1, 2, 3};
  Sudoku_group expected2 = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  Sudoku_group expected3 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
  Sudoku_group expected4 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  Sudoku_group expected5 = {8, 9, 1, 2, 3, 4, 5, 6, 7};
  Sudoku_group expected6 = {3, 4, 5, 6, 7, 8, 9, 1, 2};
  Sudoku_group expected7 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
  Sudoku_group expected8 = {9, 1, 2, 3, 4, 5, 6, 7, 8};

  Sudoku_group *expected[GROUP_SIZE] = {&expected0, &expected1, &expected2,
                                        &expected3, &expected4, &expected5,
                                        &expected6, &expected7, &expected8};
  for(int i = 0; i < GROUP_SIZE; i++){
    for(int j = 0; j < GROUP_SIZE; j++){
      int box_index = i * GROUP_SIZE + j;
      Sudoku_group *box = get_box_for_index(box_index, &solved);
      int box_number;
      switch (box_index) {
        case 0:  box_number = 0;
        break;
        case 1:  box_number = 0;
        break;
        case 2:  box_number = 0;
        break;
        case 9:  box_number = 0;
        break;
        case 10: box_number = 0;
        break;
        case 11: box_number = 0;
        break;
        case 18: box_number = 0;
        break;
        case 19: box_number = 0;
        break;
        case 20: box_number = 0;
        break;

        case 3:  box_number = 1;
        break;
        case 4:  box_number = 1;
        break;
        case 5:  box_number = 1;
        break;
        case 12: box_number = 1;
        break;
        case 13: box_number = 1;
        break;
        case 14: box_number = 1;
        break;
        case 21: box_number = 1;
        break;
        case 22: box_number = 1;
        break;
        case 23: box_number = 1;
        break;

        case 6:  box_number = 2;
        break;
        case 7:  box_number = 2;
        break;
        case 8:  box_number = 2;
        break;
        case 15: box_number = 2;
        break;
        case 16: box_number = 2;
        break;
        case 17: box_number = 2;
        break;
        case 24: box_number = 2;
        break;
        case 25: box_number = 2;
        break;
        case 26: box_number = 2;
        break;

        case 27: box_number = 3;
        break;
        case 28: box_number = 3;
        break;
        case 29: box_number = 3;
        break;
        case 36: box_number = 3;
        break;
        case 37: box_number = 3;
        break;
        case 38: box_number = 3;
        break;
        case 45: box_number = 3;
        break;
        case 46: box_number = 3;
        break;
        case 47: box_number = 3;
        break;

        case 30: box_number = 4;
        break;
        case 31: box_number = 4;
        break;
        case 32: box_number = 4;
        break;
        case 39: box_number = 4;
        break;
        case 40: box_number = 4;
        break;
        case 41: box_number = 4;
        break;
        case 48: box_number = 4;
        break;
        case 49: box_number = 4;
        break;
        case 50: box_number = 4;
        break;

        case 33: box_number = 5;
        break;
        case 34: box_number = 5;
        break;
        case 35: box_number = 5;
        break;
        case 42: box_number = 5;
        break;
        case 43: box_number = 5;
        break;
        case 44: box_number = 5;
        break;
        case 51: box_number = 5;
        break;
        case 52: box_number = 5;
        break;
        case 53: box_number = 5;
        break;

        case 54: box_number = 6;
        break;
        case 55: box_number = 6;
        break;
        case 56: box_number = 6;
        break;
        case 63: box_number = 6;
        break;
        case 64: box_number = 6;
        break;
        case 65: box_number = 6;
        break;
        case 72: box_number = 6;
        break;
        case 73: box_number = 6;
        break;
        case 74: box_number = 6;
        break;

        case 57: box_number = 7;
        break;
        case 58: box_number = 7;
        break;
        case 59: box_number = 7;
        break;
        case 66: box_number = 7;
        break;
        case 67: box_number = 7;
        break;
        case 68: box_number = 7;
        break;
        case 75: box_number = 7;
        break;
        case 76: box_number = 7;
        break;
        case 77: box_number = 7;
        break;

        case 60: box_number = 8;
        break;
        case 61: box_number = 8;
        break;
        case 62: box_number = 8;
        break;
        case 69: box_number = 8;
        break;
        case 70: box_number = 8;
        break;
        case 71: box_number = 8;
        break;
        case 78: box_number = 8;
        break;
        case 79: box_number = 8;
        break;
        case 80: box_number = 8;
        break;
      }                       
      if(!groups_equals(box, expected[box_number])){
        s_log(ERROR, __func__, "Failed at index %d", box_index);
        return false;
      }
    }
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_valid_position_for_number(){
  s_log(INFO, __func__, "Running");
  int valid1 = 3, invalid_row1 = 2, invalid_column1 = 6, invalid_box1 = 4, position1 = 0;
  if(!is_valid_position_for_number(valid1, &unfinished, position1)){
    s_log(ERROR, __func__, "Value %d should be valid for position %d", valid1, position1);
    return false;
  }
  if(is_valid_position_for_number(invalid_row1, &unfinished, position1)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (row clash) %d", invalid_row1, position1);
    return false;
  }
  if(is_valid_position_for_number(invalid_column1, &unfinished, position1)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (column clash) %d", invalid_column1, position1);
    return false;
  }
  if(is_valid_position_for_number(invalid_box1, &unfinished, position1)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (box clash) %d", invalid_box1, position1);
    return false;
  }

  int valid2 = 4, invalid_row2 = 9, invalid_column2 = 8, invalid_box2 = 2, position2 = 51;
  if(!is_valid_position_for_number(valid2, &unfinished, position2)){
    s_log(ERROR, __func__, "Value %d should be valid for position %d", valid2, position2);
    return false;
  }
  if(is_valid_position_for_number(invalid_row2, &unfinished, position2)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (row clash) %d", invalid_row2, position2);
    return false;
  }
  if(is_valid_position_for_number(invalid_column2, &unfinished, position2)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (column clash) %d", invalid_column2, position2);
    return false;
  }
  if(is_valid_position_for_number(invalid_box2, &unfinished, position2)){
    s_log(ERROR, __func__, "Value %d should not be valid for position (box clash) %d", invalid_box2, position2);
    return false;
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_is_solved_group() {
  s_log(INFO, __func__, "Running");

  Sudoku_group valid = {9, 2, 7, 4, 3, 6, 1, 5, 8};
  if (!is_solved_group(&valid)) {
    s_log(ERROR, __func__, "Group shoud be valid");
    return false;
  }

  Sudoku_group invalid = {1, 1, 3, 4, 5, 6, 7, 8, 9};
  if (is_solved_group(&invalid)) {
    s_log(ERROR, __func__, "Group shoud not be valid");
    return false;
  }

  Sudoku_group too_few = {1, 2, 3};
  if (is_solved_group(&too_few)) {
    s_log(ERROR, __func__, "Group shoud not be valid");
    return false;
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_is_solved() {
  s_log(INFO, __func__, "Running");
  if(!is_solved(&solved)){
    s_log(ERROR, __func__, "This Sudoku IS correctly solved");
    return false;
  }
  if(is_solved(&unsolved)){
    s_log(ERROR, __func__, "This Sudoku is NOT correctly solved");
    return false;
  }
  if(is_solved(&unfinished)){
    s_log(ERROR, __func__, "This Sudoku is NOT done");
    return false;
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

int main(int argc, char *argv[]) {
  s_log(INFO, __func__, "Hello tester!");

  return EXIT_SUCCESS || !(test_is_solved_group() &&
         test_is_solved() && test_get_row() && test_get_column() &&
         test_get_box() && test_valid_position_for_number());
}
