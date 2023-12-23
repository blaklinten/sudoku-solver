#include <stdio.h>
#include <stdlib.h>

#include "solver.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  printf("Hello Sudoku! \n");
  Sudoku *s = get_sudoku_from_stdin();

  if(!is_solved(s)){
    brute_force_single_thread(s);
  }

  free(s);
  return EXIT_SUCCESS;
}

