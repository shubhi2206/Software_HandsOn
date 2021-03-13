/*
	Write a program to create a Zombie state of the running program.
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
	pid_t child_pid = fork(); 
  
    	// Parent process  
    	if (child_pid > 0) {
        	sleep(50);
        	printf("Parent Process is awake after 15 seconds\n"); 
        }
  
    // Child process 
    	else {  
    		printf("Child Process : %d\n", getpid());     
        	exit(0); 
  	}
    	return 0;
}
