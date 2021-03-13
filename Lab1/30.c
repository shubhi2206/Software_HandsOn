#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	pid_t pid = 0;
	pid = fork();
	
	if( pid > 0){
		printf("Child ID: %d\n", pid);
		exit(0);   // Parent process needs to be killed
	}
	else {
		umask(0);
		setsid();   //setsid() function to run the process in new session and have a new group
		chdir("/");
		while(1){
			sleep(5);
			printf("Daemon Process is running...\n");
		}
	}
}
