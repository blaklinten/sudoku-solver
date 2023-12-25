#ifndef SOLVER
#define SOLVER

#include "models/sudoku.h"

void brute_force_single_thread(Sudoku *);
void shuffle_until_solved(Sudoku *);

#endif // !SOLVER
