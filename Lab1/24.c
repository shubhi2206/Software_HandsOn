/*
	Write a program to create a orphan process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int pid = fork();
	if (pid > 0)
	{
		printf("Parent process ID: %d\n", getpid()); // Parent Process
	}
	else
	{
		printf("Child process ID: %d\n", getpid());		// Before Orphan state
		printf("Parent Process ID: %d\n\n",getppid()); 

		sleep(5);

		printf("Child process ID: %d\n", getpid());		// After being orphan, child now has init process as parent
		printf("Parent Process ID: %d\n\n",getppid());
	}
	
	
	return 0;

}
