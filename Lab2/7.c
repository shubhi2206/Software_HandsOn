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
	static int num = 0 ;
	num++;
	printf("Thread number : %d\n", num);
	printf("Thread ID : %ld\n", pthread_self());         // Printing thread ID
	
	return 0;
}

int main(int agrc, int const argv[]){
	pthread_t threads;
	for(int i = 0; i < 3; i++){
		if(pthread_create(&threads, NULL, thread_creation, (void*)&i) < 0){
			perror("Creation Error: ");
			return 1;
		}
		else
			sleep(1);
	}
	pthread_exit(NULL);
	return 0;
}
