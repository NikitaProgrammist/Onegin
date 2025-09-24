#ifndef SORTS_H
#define SORTS_H

typedef int (* Cmp)(const void * a, const void * b);

enum SortType {
  BUBBLE,
  MYQSORT,
  QSORT
};

enum CmpType {
  START,
  END
};

void choiceSort(Text * text, SortType sort_type, CmpType cmp_type);
Cmp choiceCmp(CmpType cmp_type);
void bubbleSort(void * array, size_t len, size_t typesize, int (* myCmp)(const void * a, const void * b));
void naiveQuickSort(void * array, size_t len, size_t typesize, int (* myCmp)(const void * a, const void * b));
void swap(void * a, void * b, size_t typesize);
int mySortCmpStartStr(const void * a, const void * b);
int mySortCmpEndStr(const void * a, const void * b);

#endif // SORTS_H
