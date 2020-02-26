#ifndef _HELLOGS_H_
#define _HELLOGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

struct hellog_t {
	char * filename;
	FILE * fp;
};

typedef struct hellog_t hellog_t;

hellog_t * hellog_create(char * filename);
void hellog_close(hellog_t * log);
int hellog_write(hellog_t * log, const char * log_msg);

#endif //_HELLOGS_H_
