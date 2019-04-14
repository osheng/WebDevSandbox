#include "helper.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>



/*an error checked version of malloc*/
void *malloc_or_exit(size_t size){
  void *p = malloc(size);
  if (p==NULL){
    perror("malloc_or_exit");
    exit(1);
  }
  return p;
}

/*an error checked version of realloc*/
void *realloc_or_exit(void *ptr, size_t size){
  void *p = realloc_or_exit(ptr, size);
  if (p==NULL){
    perror("realloc_or_exit");
    exit(1);
  }
  return p;
}

/*an error checked version of fopen*/
FILE* fopen_or_exit(const char *file, const char *mode){
  FILE* p = fopen(file, mode);
  if (p==NULL){
    perror("fopen_or_exit");
    exit(1);
  }
  return p;
}

/*read a file into a buffer*/
char *read_file(FILE* fp){
  char *buf = malloc_or_exit(1024);
  buf[0] = '\0';
  char *rest = buf;
  char temp_buf[LINE];

  while (fgets(temp_buf, LINE, fp) != NULL){
    if (sizeof(rest)-sizeof(temp_buf) < 1){
      buf = realloc_or_exit(buf, sizeof(buf) * 2);
    }
    strncat(buf, temp_buf, strlen(temp_buf));
    rest = strchr(buf, '\0');
  }
  return buf;
}
