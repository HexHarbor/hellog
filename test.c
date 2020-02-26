#include "hellogs.h"



int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Usage: ./test str\n");
		return 0;
	}

	hellog_t * test = hellog_create("test.log");
	if(test == NULL){
		fprintf(stderr,"Failed to create log file or log object\n");
		hellog_close(test);
	}

	int err = hellog_write(test,argv[1]);
	if(err != 0){
		fprintf(stderr,"<hellog_write> Returned %d\n", err);
		hellog_close(test);
		return -1;
	}
	hellog_close(test);
	return 0;
}
