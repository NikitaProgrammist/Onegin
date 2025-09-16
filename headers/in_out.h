#ifndef IN_OUT_H
#define IN_OUT_H

struct Text {
  char * buffer;
  char ** array;
  size_t len;
  size_t str_count;
};

enum Errors {
  SUCCESS,
  EXIT,
  CONTINUE,
  FIND_EOF,
  ASSERT_FAILED,
  OPEN_FILE_ERROR,
  CALLOC_FAILED
};

Errors readFile(Text * text, char * filename);
Errors writeFile(Text * text, char * filename);
size_t getFileSize(FILE * fp);
void getBuffer(FILE * fp, Text * text);
void getArray(Text * text);

#endif // IN_OUT_H
