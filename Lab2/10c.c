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
#include<pthread.h>
#include<fcntl.h>

void signal_handler(int signal_no){
	printf(" SIGFPE: %d caught!\n", signal_no);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	if(sigaction(SIGFPE,&sa,NULL)==-1)                       // Using SIGACTION to catch Floating point error
	{
		perror("Error");
	}
	raise(SIGFPE);

	return 0;
}
