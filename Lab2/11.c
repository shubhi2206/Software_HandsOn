/*
	11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
*/

#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<fcntl.h>



int main() {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	if(sigaction(SIGINT,&sa,NULL)==-1){
		perror("Error");
	}
	printf("Ignoring SIGINT\n");
	sleep(5);
	printf("No action within 5 seconds\n"); //ctrl+c wont work for 5 seconds.
	
	sa.sa_handler = SIG_DFL;
	if(sigaction(SIGINT,&sa,NULL)==-1){
		perror("Error");
	}
	printf("Resetting back to default action of SIGINT\n");
	sleep(3);
	printf("No action within 3 seconds\n"); //ctrl+c started working again. 

	return 0;
}
