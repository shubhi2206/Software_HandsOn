#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void signal_handler(int signal_no){
	printf("SIGALARM caught after 2 second!\nSignal number: %d\n", signal_no);
}

int main(int agrc, int const argv[]){
	signal(SIGALRM, &signal_handler);
		
	alarm(2);
	
	pause();
	
}
