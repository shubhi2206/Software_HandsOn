/*
	Write a program to measure how much time is taken to execute 100 getppid ( )
	system call. Use time stamp counter.
*/

#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

unsigned long long rdtsc(void) {
	unsigned long long t;
	__asm__ __volatile__("rdtsc" : "=A"(t));     // Make the program run on the same core
	return t;
}

int main(int agrc, int const argv[]){
	long long int start, end;
	start = rdtsc();                            // Start counting
	
	printf("Intial vlaue of counter: %llu\n", start);
	for(int i = 0; i < 100; i++){
		getppid();
	}
	
	end = rdtsc();                              // End counting
	printf("End valuee of counter: %llu\n", end);
	end = end - start;
	printf("Number of cycles : %llu\n", end);
	return 0;
}
