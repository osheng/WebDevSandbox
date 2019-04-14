#include <stdio.h>

#define LINE 256

FILE* fopen_or_exit(const char *file, const char *mode);
void *malloc_or_exit(size_t size);
char *read_file(FILE* fp);
void *realloc_or_exit(void *ptr, size_t size);
