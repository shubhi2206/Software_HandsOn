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
	int k, pid;
	printf("Enter the PID of the process: ");
	scanf("%d", &pid);
	printf("Sending SIGSTOP to %d\n", pid);
	k = kill(pid, SIGSTOP);
	return 0;
}
