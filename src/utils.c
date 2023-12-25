#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

Sudoku * get_copy(Sudoku *s){
  Sudoku *new = malloc(sizeof(Sudoku));
  for(int i = 0; i < SUDOKU_SIZE; i++){
    (*new)[i] = (*s)[i];
  }
  return new;
}

void s_print(Sudoku *s){
  for(int i = 0; i < GROUP_SIZE; i++){
    for(int j = 0; j < GROUP_SIZE; j++){
    printf("%d", (*s)[i * GROUP_SIZE + j]);
    }
    printf("\n");
  }
  printf("---------\n");
}

Sudoku *get_sudoku_from_stdin() {

  char user_input[SUDOKU_SIZE * 2 + 1];
  printf("Input sudoku numbers as rows, numbers seperated with comma \",\".\n");
  int characters_read = strlen(fgets(user_input, sizeof(user_input), stdin));
  if (characters_read != SUDOKU_SIZE * 2) {
    printf("LOL, wrong number of characters. I read %d, wanted %d\n",
           characters_read, SUDOKU_SIZE * 2);
    exit(1);
  };
  Sudoku *s = malloc(sizeof(Sudoku));
  for (int i = 0, j = 0; i < SUDOKU_SIZE; i++, j++) {
    (*s)[i] = atoi(&user_input[j++]);
  }
  return s;
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
