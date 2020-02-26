#include "hellogs.h"



hellog_t * hellog_create(char * filename){
	new_log->filename = filename;
	new_log->fp = fopen(new_log->filename, "a");
	if (new_log->fp == NULL){
		return NULL;
	}
	
	hellog_t * new_log = malloc(sizeof(hellog_t));
	if ( new_log == NULL )
		return NULL;

	return new_log;
}

void hellog_close(hellog_t * log){
	if ( log != NULL){
		fclose(log->fp);
		free(log);
	}
	if ( log->fp != NULL )
	{
		fclose(log->fp);
	}
}

int hellog_write(hellog_t * log, const char * log_msg){
	if (log->fp == NULL || log == NULL)
		return -1;
	char time_string[500];
	time_t t = time(NULL);
	struct tm * tmp = localtime(&t);
	if (tmp == NULL){
		fprintf(stderr,"Error calling <localtime> on (t)\n");
		return -1;
	}
	//eg Tue Jan 8 2020 12:30:40PM
	if (strftime(time_string, sizeof(time_string), "%a %b %d %Y %I:%M:%S%p", tmp) == 0){
		fprintf(stderr, "<strftime> failed with 0\n");
		return -1;
	}
	fprintf(log->fp,"%s\t%s\n", time_string, log_msg);
	return 0;
}
