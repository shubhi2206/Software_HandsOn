/*
	Write a simple program to create three threads.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

void *thread_creation(void *i){
	static int num = 0;
	++num;
	printf("Thread %d Created...\n", num);
	return NULL;
}

int main(int agrc, int const argv[]){
	pthread_t threads;                       //Unique Identifier
	for(int i = 0; i < 3; i++){              // Creating 3 threads
		pthread_create(&threads, NULL, thread_creation, NULL);
		sleep(1);
	}
	
	pthread_exit(NULL);
	return 0;
}
