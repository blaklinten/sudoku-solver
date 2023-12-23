#include <stdio.h>
#include <stdlib.h>

#include "models/sudoku.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  printf("Hello Sudoku! \n");
  Sudoku *s = get_sudoku_from_stdin();
  for (int i = 0; i < SUDOKU_SIZE; i++){
    if(i % GROUP_SIZE == 0){
      printf("\n");
    }
    printf("%d", (*s)[i]);
  }
  //TODO actually solve the Sudoku
  exit(0);

  while(!is_solved(s)){
    
  }

  free(s);
  return EXIT_SUCCESS;
}
