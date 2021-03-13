/*
	12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
	the parent process from the child process.

*/

#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<fcntl.h>

int main(){
	if(!fork()){
		int val,ppid1,ppid2;
		ppid1=getppid();
		printf("PPID before orphan: %d\n",ppid1);
		val=kill(ppid1,SIGKILL);
		sleep(2);
		ppid2=getppid();
		printf("PPID after orphan: %d\n",ppid2);
	}
	
	return 0;

}
