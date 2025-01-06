#ifndef UTILS
#define UTILS

#include "sudoku.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef enum { ERROR, SUCCESS, INFO } LOG_LEVEL;

/**
 * s_ to not override built in function log from math.h
 **/
void s_log(LOG_LEVEL, const char *, ...);
void s_print(Sudoku *);

Sudoku *get_sudoku_from_stdin();
Sudoku_list get_sudokus_from_file(const char*);
Sudoku *get_copy(Sudoku *);

#endif // !UTILS
