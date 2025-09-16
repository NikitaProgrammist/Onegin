#include <stdio.h>
#include <stdlib.h>

#include "my_printf.h"
#include "in_out.h"
#include "print_errors.h"

void printErrorLines(const char * file, const char * func, size_t line_number) {
  colorPrintf(RED, BOLD, "file: %s:%zu\nfunc: %s\n", file, line_number, func);

  const int MAX_LINE = 150;
  char line[MAX_LINE] = {};
  FILE * fp = fopen(file, "r");

  for (size_t i = 0; i <= line_number; i++) {
    fgets(line, MAX_LINE, fp);
    if (i >= line_number - 2)
      colorPrintf(RED, BOLD, "%zu: %s", i + 1, line);
  }

  fclose(fp);
}

void errorsParser(Errors error) {
  switch (error) {
    case SUCCESS:
      break;
    case ASSERT_FAILED:
      break;
    case EXIT:
      break;
    case CONTINUE:
      break;
    case FIND_EOF:
      colorPrintf(RED, PRIMARY, "Конец ввода.");
      break;
    case OPEN_FILE_ERROR:
      colorPrintf(RED, PRIMARY, "Ошибка при открытии файла.");
      break;
    case CALLOC_FAILED:
      colorPrintf(RED, PRIMARY, "Ошибка во время выделения памяти.");
      break;
    default:
      colorPrintf(RED, PRIMARY, "Непредвиденная ошибка.");
      break;
  }
}
