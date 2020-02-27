#include "hellogs.h"

hellog_t* hellog_create(char* filename) {
  hellog_t* new_log = malloc(sizeof(hellog_t));
  if (new_log == NULL) { return NULL; }

  new_log->filename = filename;
  
  new_log->fp = fopen(new_log->filename, "a");
  if (new_log->fp == NULL) {
    free(new_log);
    return NULL;
  }
  
  return new_log;
}

void hellog_close(hellog_t* log) {
  if (log == NULL || log->fp == NULL) { return; }
  
  fclose(log->fp);
  free(log);
}

int hellog_write(hellog_t* log, const char* log_msg) {
  if (log == NULL || log->fp == NULL) { return -1; }
  
  char time_string[500];
  time_t t = time(NULL);
  struct tm* tmp = localtime(&t);
  
  if (tmp == NULL) {
    fprintf(stderr, "Error calling <localtime> on (t)\n");
    return -1;
  }
  
  if (strftime(time_string, sizeof(time_string), "%a %b %d %Y %I:%M:%S%p",
               tmp) == 0) {
    fprintf(stderr, "<strftime> failed with 0\n");
    return -1;
  }
  
  fprintf(log->fp, "%s\t%s\n", time_string, log_msg);
  return 0;
}
