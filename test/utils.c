#include "utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool groups_equals(Sudoku_group *first, Sudoku_group *second) {
  for (int i = 0; i < GROUP_SIZE; i++) {
    if ((*first)[i] != (*second)[i]) {
      s_log(ERROR, __func__, "Groups differ at locaion %d; %d != %d", i,
            (*first)[i], (*second)[i]);
      return false;
    }
  }
  return true;
}

void s_log(LOG_LEVEL level, const char *func, ...) {
  va_list args;
  va_start(args, func);
  char *info = va_arg(args, char *);

  char *format;
  switch (level) {
  case INFO:
    format = ANSI_COLOR_YELLOW "[%s] Info: " ANSI_COLOR_RESET "%s\n";
    break;
  case ERROR:
    format = ANSI_COLOR_RED "[%s] Error: " ANSI_COLOR_RESET "%s\n";
    break;
  case SUCCESS:
    format = ANSI_COLOR_GREEN "[%s] Success: " ANSI_COLOR_RESET "%s\n";
    break;
  }

  int length = strlen(format) + strlen(func) + strlen(info);
  char *log_format = malloc(length);
  snprintf(log_format, length, format, func, info);
  vprintf(log_format, args);
  va_end(args);
}
