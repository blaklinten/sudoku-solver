#include <ctype.h>
#include <errno.h>
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
  char *system_log_level = getenv("SUDOKU_LOG_LEVEL");
  if((!system_log_level) || atoi(system_log_level) < INFO){
    return;
  }
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
  char *system_log_level = getenv("SUDOKU_LOG_LEVEL");
  if((!system_log_level) || atoi(system_log_level) < level){
    return;
  }
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

Sudoku *create_sudoku_from_csv(char csv[]) {
  Sudoku *s = malloc(sizeof(Sudoku));
  for (int i = 0, j = 0; i < SUDOKU_SIZE; i++, j = j + 2) {
    int num = atoi(&csv[j]);
    if (isdigit(csv[j]) && num <= 9 && num >= 0) {
      (*s)[i] = num;
    } else {
      s_log(ERROR, __func__,
            "Invalid character entered. Sudoku contains numbers between 0 and "
            "9; you entered %c",
            csv[j]);
      free(s);
      return NULL;
    }
  }
  return s;
}

Sudoku *get_sudoku_from_stdin() {
  printf("Input sudoku numbers as rows, numbers seperated with comma \",\".\n");
  char user_input[SUDOKU_SIZE * 2 + 1];
  int characters_read = strlen(fgets(user_input, sizeof(user_input), stdin));
  if (characters_read != SUDOKU_SIZE * 2) {
    printf("LOL, wrong number of characters. I read %d, wanted %d\n",
           characters_read, SUDOKU_SIZE * 2);
    exit(1);
  };

  return create_sudoku_from_csv(user_input);
}

Sudoku_list get_sudokus_from_file(const char *file_path) {
  FILE *file = fopen(file_path, "r");
  if (!file) {
    s_log(ERROR, __func__, "File could not be opened, errno %d", errno);
    exit(1);
  }

  int number_of_lines = 0;
  char line[SUDOKU_SIZE * 2 + 1];
  while (fgets(line, sizeof(line), file)) {
    number_of_lines++;
  }
  rewind(file);

  char sudoku[SUDOKU_SIZE * 2 + 1];
  int characters_read;
  Sudoku_list sudokus = {.size = number_of_lines,
                         .list =
                             malloc(sizeof(Sudoku *) * number_of_lines)};
  for (int i = 0; i < number_of_lines; i++) {
    characters_read = strlen(fgets(sudoku, sizeof(sudoku), file));
    if (characters_read != SUDOKU_SIZE * 2) {
      printf("LOL, wrong number of characters. I read %d, wanted %d\n",
             characters_read, SUDOKU_SIZE * 2);
      exit(1);
    };
    sudokus.list[i] = create_sudoku_from_csv(sudoku);
  }
  return sudokus;
}
