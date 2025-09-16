#include <stdio.h>
#include <stdlib.h>

#include "in_out.h"
#include "str.h"
#include "sorts.h"

void choiceSort(Text * text, SortType type) {
  switch (type) {
    case BUBBLE:
      bubbleSort(text);
      break;
    case QSORT:
      qsort(text->array, text->str_count, sizeof(char *), mySortCmpStr);
      break;
    default:
      qsort(text->array, text->str_count, sizeof(char *), mySortCmpStr);
      break;
  }
}

void bubbleSort(Text * text) {

}

int mySortCmpStr(const void * a, const void * b) {
  const char * str1 = *(const char **) a;
  const char * str2 = *(const char **) b;
  return myStrCmp(str1, str2);
}
