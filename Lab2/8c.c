#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void signal_handler(int signal_no){
	printf("SIGFPE caught!\nSignal number: %d\n", signal_no);
}

int main(int agrc, int const argv[]){
	signal(SIGFPE, &signal_handler);                   //Floating point error
	
	raise(SIGFPE);                                             // Raising FPE
	
}
