#ifndef _HELLOGS_H_
#define _HELLOGS_H_

/*
#include <malloc.h> NON STANDARD (malloc is defined in stdlib.h) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hellog_t_impl {
  char* filename;
  FILE* fp;
};

typedef struct hellog_t_impl hellog_t;

hellog_t* hellog_create(char* filename);
void hellog_close(hellog_t* log);
int hellog_write(hellog_t* log, const char* log_msg);

#endif  //_HELLOGS_H_
