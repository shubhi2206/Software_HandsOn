#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char const *argv[]){
	if(argc == 0)
		printf("No arguments found\n");
	else{
		printf("Arguments found\n");
		for(int i = 0; i < argc; i++){
			printf("%s\n", argv[i]);
		}
	}
	
	return 0;
	
}
