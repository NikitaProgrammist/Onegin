#include <stdio.h>
#include <stdlib.h>

#include "in_out.h"
#include "sorts.h"
#include "print_errors.h"
#include "my_printf.h"
#include "str.h"

int main(int argc, char * argv[]) {
  Text text = {};
  SortType sort_type = MYQSORT;
  CmpType cmp_type = START;
  Errors result = readFile(&text, "../sources/text.txt");

  errorsParser(result);
  if (result != SUCCESS) {
    return 1;
  }

  choiceSort(&text, sort_type, cmp_type);

  result = writeFile(&text, "../sources/sorttext.txt");
  errorsParser(result);

  free(text.buffer);
  free(text.array);
  return 0;
}
