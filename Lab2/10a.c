/*
	10. Write a separate program using sigaction system call to catch the following signals.
	a. SIGSEGV
	b. SIGINT
	c. SIGFPE
*/

#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int signal_no){
	printf("SIGSEGV: %d signal caught\n", signal_no);
}

int main(void){
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	if(sigaction(SIGSEGV,&sa,NULL)==-1)                       // USing SIGACTION to catch Segmentation fault
	{
		perror("Error");
	}
	raise(SIGSEGV);

	return 0;
}
