#include <stdbool.h>
#include <stdlib.h>

#include "../src/models/sudoku.h"
#include "utils.h"

Sudoku solved = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                 4, 5, 6, 7, 8, 9, 1, 2, 3,
                 7, 8, 9, 1, 2, 3, 4, 5, 6,
                 2, 3, 4, 5, 6, 7, 8, 9, 1,
                 5, 6, 7, 8, 9, 1, 2, 3, 4,
                 8, 9, 1, 2, 3, 4, 5, 6, 7,
                 3, 4, 5, 6, 7, 8, 9, 1, 2,
                 6, 7, 8, 9, 1, 2, 3, 4, 5,
                 9, 1, 2, 3, 4, 5, 6, 7, 8};

bool test_get_row() {
  s_log(INFO, __func__, "Running");
  Sudoku_group *row0 = get_row(0, solved);
  Sudoku_group expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  if (!groups_equals(row0, &expected)) {
    return false;
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_column() {
  s_log(INFO, __func__, "Running");
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_get_box() {
  s_log(INFO, __func__, "Running");
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_assert_valid_sudoku_group() {
  s_log(INFO, __func__, "Running");

  Sudoku_group valid = {9, 2, 7, 4, 3, 6, 1, 5, 8};
  if (!assert_valid_sudoku_group(valid)) {
    s_log(ERROR, __func__, "Group shoud be valid");
    return false;
  }

  Sudoku_group invalid = {1, 1, 3, 4, 5, 6, 7, 8, 9};
  if (assert_valid_sudoku_group(invalid)) {
    s_log(ERROR, __func__, "Group shoud not be valid");
    return false;
  }

  Sudoku_group too_few = {1, 2, 3};
  if (assert_valid_sudoku_group(too_few)) {
    s_log(ERROR, __func__, "Group shoud not be valid");
    return false;
  }
  s_log(SUCCESS, __func__, "OK");
  return true;
}

bool test_assert_valid_sudoku() {
  s_log(INFO, __func__, "Running");
  s_log(SUCCESS, __func__, "OK");
  return true;
}

int main(int argc, char *argv[]) {
  s_log(INFO, __func__, "Hello tester!");

  return EXIT_SUCCESS | test_assert_valid_sudoku_group() |
         test_assert_valid_sudoku() | test_get_row() | test_get_column() |
         test_get_box();
}
