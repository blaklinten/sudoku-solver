#include <stdio.h>
#include <stdlib.h>

#include "solver.h"
#include "utils.h"

Sudoku unfinished = {0, 0, 0, 0, 0, 2, 1, 5, 7,
                     0, 0, 0, 3, 0, 0, 8, 6, 0,
                     1, 4, 0, 0, 8, 0, 0, 0, 0,
                     0, 0, 0, 0, 5, 4, 0, 2, 6,
                     0, 0, 0, 0, 0, 0 ,0, 0, 0,
                     0, 9, 6, 0, 0, 7, 0, 0, 0,
                     6, 5, 0, 0, 2, 3, 0, 0, 0,
                     9, 0, 0, 0, 0, 0, 0, 0, 3,
                     8, 7, 0, 0, 0, 0, 0, 9, 0};


int main(int argc, char *argv[]) {
  printf("Hello Sudoku! \n");
  for(int i = 0; i < 1000; i++){
    brute_force_single_thread(&unfinished);
  }
  s_print(&unfinished);
  // Sudoku *s = get_sudoku_from_stdin();
  // free(s);
  return EXIT_SUCCESS;
}

