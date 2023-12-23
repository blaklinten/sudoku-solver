#include <stdlib.h>

#include "../src/models/sudoku.h"
#include "../src/utils.h"

Sudoku solved = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                 4, 5, 6, 7, 8, 9, 1, 2, 3,
                 7, 8, 9, 1, 2, 3, 4, 5, 6,
                 2, 3, 4, 5, 6, 7, 8, 9, 1,
                 5, 6, 7, 8, 9, 1, 2, 3, 4,
                 8, 9, 1, 2, 3, 4, 5, 6, 7,
                 3, 4, 5, 6, 7, 8, 9, 1, 2,
                 6, 7, 8, 9, 1, 2, 3, 4, 5,
                 9, 1, 2, 3, 4, 5, 6, 7, 8};
Sudoku unsolved = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                   4, 4, 6, 7, 8, 9, 1, 2, 3,
                   7, 8, 9, 1, 2, 3, 4, 5, 6,
                   2, 3, 4, 5, 6, 7, 8, 9, 1,
                   5, 6, 7, 8, 9, 1, 2, 3, 4,
                   8, 9, 1, 2, 3, 4, 5, 6, 7,
                   3, 4, 5, 6, 7, 8, 9, 1, 2,
                   6, 7, 8, 9, 1, 2, 3, 4, 5,
                   9, 1, 2, 3, 4, 5, 6, 7, 8};
Sudoku unfinished = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                     4, 5, 6, 7, 8, 9, 1, 2, 3,
                     7, 8, 9, 1, 2, 3, 4, 5, 6,
                     2, 3, 4, 5, 6, 7, 8, 9, 1,
                     5, 6, 7, 8, 9, 1, 2, 3, 4,
                     8, 9, 1, 2, 3, 4, 5, 6, 7,
                     3, 4, 5, 6, 7, 0, 9, 1, 2,
                     6, 7, 8, 9, 1, 2, 3, 4, 5,
                     9, 1, 2, 3, 4, 5, 6, 7, 8};

bool test_get_row() {
  s_log(INFO, __func__, "Running");
  Sudoku_group *row0 = get_row(0, &solved);
  Sudoku_group expected0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Sudoku_group *row3 = get_row(3, &solved);
  Sudoku_group expected3 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
  Sudoku_group *row8 = get_row(8, &solved);
  Sudoku_group expected8 = {9, 1, 2, 3, 4, 5, 6, 7, 8};
  if (!groups_equals(row0, &expected0) ||
      !groups_equals(row3, &expected3) ||
      !groups_equals(row8, &expected8)) {
    free(row0);
    free(row3);
    free(row8);
    s_log(ERROR, __func__, "Failed");
    return false;
  }
  free(row0);
  free(row3);
  free(row8);
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_column() {
  s_log(INFO, __func__, "Running");
  Sudoku_group *column0 = get_column(0, &solved);
  Sudoku_group expected0 = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  Sudoku_group *column4 = get_column(4, &solved);
  Sudoku_group expected4 = {5, 8, 2, 6, 9, 3, 7, 1, 4};
  Sudoku_group *column8 = get_column(8, &solved);
  Sudoku_group expected8 = {9, 3, 6, 1, 4, 7, 2, 5, 8};
  if (!groups_equals(column0, &expected0) ||
      !groups_equals(column4, &expected4) ||
      !groups_equals(column8, &expected8)) {
    free(column0);
    free(column4);
    free(column8);
    s_log(ERROR, __func__, "Failed");
    return false;
  }
  free(column0);
  free(column4);
  free(column8);
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_box() {
  s_log(INFO, __func__, "Running");
  Sudoku_group *box0 = get_box(0, &solved);
  Sudoku_group expected0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Sudoku_group *box4 = get_box(4, &solved);
  Sudoku_group expected4 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  Sudoku_group *box8 = get_box(8, &solved);
  Sudoku_group expected8 = {9, 1, 2, 3, 4, 5, 6, 7, 8};
  if (!groups_equals(box0, &expected0) ||
      !groups_equals(box4, &expected4) ||
      !groups_equals(box8, &expected8)) {
    free(box0);
    free(box4);
    free(box8);
    s_log(ERROR, __func__, "Failed");
    return false;
  }
  free(box0);
  free(box4);
  free(box8);
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
         test_get_box());
}
