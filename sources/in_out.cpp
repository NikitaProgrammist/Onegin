#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "in_out.h"

Errors readFile(Text * text, char * filename) {
  FILE * fp = fopen(filename, "r");
  if (fp == NULL) {
    return OPEN_FILE_ERROR;
  }

  text->len = getFileSize(fp);
  text->buffer = (char *) calloc((text->len + 1), sizeof(char));

  if (text->buffer == NULL) {
    return CALLOC_FAILED;
  }

  getBuffer(fp, text);
  text->array = (char **) calloc(text->str_count, sizeof(char *));

  if (text->array == NULL) {
    return CALLOC_FAILED;
  }

  getArray(text);

  fclose(fp);
  return SUCCESS;
}

size_t getFileSize(FILE * fp) {
  struct stat st = {};
  if (fstat(fileno(fp), &st) == 0) {
    return (size_t) st.st_size;
  }
  return 0;
}

void getBuffer(FILE * fp, Text * text) {
  char symbol = '\0';
  size_t index = 0;
  while ((symbol = (char) getc(fp)) != EOF) {
    text->buffer[index++] = symbol;
    if (symbol == '\n') {
      text->str_count++;
    }
  }
  text->buffer[index] = '\0';
}

void getArray(Text * text) {
  text->array[0] = text->buffer;
  for (size_t index = 0, strindex = 1; index < text->len - 1; index++) {
    if (text->buffer[index] == '\n') {
      text->buffer[index] = '\0';
      text->array[strindex++] = text->buffer + index + 1;
    }
  }
}
