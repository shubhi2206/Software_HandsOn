#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void signal_handler(int signal_no){                                //function to handle Segmentation fault signal 
	printf("SIGSEGV caught!\nSignal number: %d\n", signal_no);
}

int main(int agrc, int const argv[]){
	signal(SIGSEGV, &signal_handler);                
		
	raise(SIGSEGV);                                           // Raising Segmeantation fault!
	
}
