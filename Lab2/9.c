/*
	9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
	signal - Use signal system call.

*/

#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<fcntl.h>



int main(){
	
	signal(SIGINT,SIG_IGN);
	printf("Ignoring SIGINT\n");                          //Ignoring SIGINT Signal i.e. CTRL+C
	sleep(5);
	printf("SIGINT ignored for 5 seconds\n");

	signal(SIGINT,SIG_DFL);
	printf("Setting it back to default\n");               // Setting back to default
	sleep(6);
	printf("No SIGINT observed withing 6 second!\n");
	

	
	return 0;
}
