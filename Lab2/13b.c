/*
	Write two programs: first program is waiting to catch SIGSTOP signal, the second program
	will send the signal (using kill system call). Find out whether the first program is able to catch
	the signal or not.
*/
#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<fcntl.h>

int main(){
	signal(SIGSTOP, SIG_DFL);
	printf("PID of the process: %d\n ", getpid());
	printf("Press Enter to catch!\n");
	
	getchar();
	printf("Catching SIGSTOP! \n");
	sleep(10);
	printf("No signal catched!\n");
	return 0;
}
