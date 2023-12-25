#include "solver.h"
#include "models/sudoku.h"
#include "utils.h"
#include <stdlib.h>

void shuffle_until_solved(Sudoku *s){
  s_log(INFO, __func__, "Attempting shuffle solution");
  Sudoku *temp;
  while(!is_solved(temp)){
    temp = get_copy(s);
    for(int i = 0; i < SUDOKU_SIZE; i++){
      (*temp)[i] = (*s)[i];
    }
    for(int i = 0; i < SUDOKU_SIZE; i++){
      if(!temp[i]){
        (*temp)[i]= rand() % 9;
      }
    }
    s_log(INFO, __func__, "Current try:\n");
    s_print(temp);
  }
  s_log(SUCCESS, __func__, "Solved!\nSolution is:\n");
  s_print(temp);
}

void brute_force_single_thread(Sudoku *original){
  s_log(INFO, __func__, "Attempting bfst solution");
  Sudoku *working_copy = get_copy(original);
  s_log(INFO, __func__, "Copy of input sudoku:");
  s_print(working_copy);
  // Solving loop BEGIN
  for(int i = 0; i < SUDOKU_SIZE; i++){
    if(i < 0){
      s_log(ERROR, __func__, "No solution found :(");
      exit(1);
    }
    if((*original)[i]){
      continue;
    }
    int value = (*working_copy)[i];
    if(++value > 9){
      (*working_copy)[i] = 0;
      i--;
      while((*original)[i]){
        i--;
      }
      i--;
      continue;
    }

    if(!is_valid_position_for_number(value, working_copy, i)){
      (*working_copy)[i] = value;
      i--;
    } else {
      (*working_copy)[i] = value;
    }

    //Debug purpose
    s_print(working_copy);
    char tmp[2];
    fgets(tmp, 2, stdin);
  }
}

