#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Sudoku * get_sudoku_from_stdin(){

  char user_input[SUDOKU_SIZE * 2 + 1];
  printf("Input sudoku numbers as rows, numbers seperated with comma \",\".\n");
  int characters_read = strlen(fgets(user_input, sizeof(user_input), stdin));
  if (characters_read  != SUDOKU_SIZE * 2){
    printf("LOL, wrong number of characters. I read %d, wanted %d\n", characters_read, SUDOKU_SIZE * 2);
    exit(1);
  };
  Sudoku *s = malloc(sizeof(Sudoku));
  for (int i = 0, j = 0; i < SUDOKU_SIZE; i++, j++){
    (*s)[i] = atoi(&user_input[j++]);
  }
  return s;
}