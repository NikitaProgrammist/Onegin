#include <stdio.h>
#include <stdlib.h>

#include "in_out.h"
#include "str.h"
#include "sorts.h"

void choiceSort(Text * text, SortType sort_type, CmpType cmp_type) {
  switch (sort_type) {
    case BUBBLE:
      bubbleSort(text->array, text->str_count, sizeof(char *), choiceCmp(cmp_type));
      break;
    case QSORT:
      qsort(text->array, text->str_count, sizeof(char *), choiceCmp(cmp_type));
      break;
    default:
      qsort(text->array, text->str_count, sizeof(char *), choiceCmp(cmp_type));
      break;
  }
}

myCmp choiceCmp(CmpType cmp_type) {
  switch (cmp_type) {
    case START:
      return mySortCmpStartStr;
    case END:
      return mySortCmpEndStr;
    default:
      return mySortCmpStartStr;
  }
}

void bubbleSort(void * array, size_t len, size_t typesize, int (* myCmp)(const void * a, const void * b)) {
  for (size_t i = 0; i < len - 1; i++) {
    int flag = 1;
    for (size_t j = 0; j < len - i - 1; j++) {
      if (myCmp((char *) array + typesize * j, (char *) array + typesize * (j + 1)) > 0) {
        swap((char *) array + typesize * j, (char *) array + typesize * (j + 1), typesize);
        flag = 0;
      }
    }
    if (flag) {
      break;
    }
  }
}

void swap(void * a, void * b, size_t typesize) {
  char *ptr1 = (char *)a;
  char *ptr2 = (char *)b;
  for (size_t i = 0; i < typesize; i++) {
    char temp = ptr1[i];
    ptr1[i] = ptr2[i];
    ptr2[i] = temp;
  }
}

int mySortCmpStartStr(const void * a, const void * b) {
  const char * str1 = *(const char **) a;
  const char * str2 = *(const char **) b;
  return myStrCmpStart(str1, str2);
}

int mySortCmpEndStr(const void * a, const void * b) {
  const char * str1 = *(const char **) a;
  const char * str2 = *(const char **) b;
  return myStrCmpEnd(str1, str2);
}
