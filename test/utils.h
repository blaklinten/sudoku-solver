#ifndef UTILS
#define UTILS

#include <stdbool.h>

#include "../src/models/sudoku.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef enum { INFO, ERROR, SUCCESS } LOG_LEVEL;

/**
 * s_ to not override built in function log from math.h
 **/
void s_log(LOG_LEVEL, const char *, ...);

bool groups_equals(Sudoku_group *, Sudoku_group *);

#endif // !UTILS
