#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void signal_handler(int signal_no){
	printf("SIGINT caught!\nSignal number: %d\n", signal_no);
}

int main(int agrc, int const argv[]){
	signal(SIGINT, &signal_handler);                       //Interrupt from keyboard
	sleep(5);
	printf("No Interrupt detected!\n");
	
}
