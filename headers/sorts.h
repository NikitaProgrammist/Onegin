#ifndef SORTS_H
#define SORTS_H

enum SortType {
  BUBBLE,
  QSORT
};

void choiceSort(Text * text, SortType type);
void bubbleSort(void * array, size_t len, size_t typesize, int (* myCmp)(const void * a, const void * b));
void swap(void * a, void * b, size_t typesize);
int mySortCmpStr(const void * a, const void * b);

#endif // SORTS_H
