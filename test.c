#include "hellogs.h"



int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Usage: ./test str\n");
		exit(0);
	}

	hellog_t * test = hellog_create("test.log");
	if(test == NULL)
		fprintf(stderr,"Failed to create log file\n");

	int err = hellog_write(test,argv[1]);
	if(err != 0){
		fprintf(stderr,"<hellog_write> Returned %d\n", err);
		return -1;
	}
	hellog_close(test);
	return 0;
}
