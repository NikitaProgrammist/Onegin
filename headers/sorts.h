#ifndef SORTS_H
#define SORTS_H

enum SortType {
  BUBBLE,
  QSORT
};

void choiceSort(Text * text, SortType type);
void bubbleSort(Text * text);
int mySortCmpStr(const void * a, const void * b);

#endif // SORTS_H
