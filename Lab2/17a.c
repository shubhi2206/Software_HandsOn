/*
	Write a program to execute ls -l | wc.
	a. use dup
	b. use dup2
	c. use fcntl
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


int main(int agrc, int const argv[]){
	int fd[2];
	pipe(fd);
	
	if(!fork()){
		close(1);             // Closing Standard Ouput
		dup(fd[1]);           // Duplicating file descriptor with lowest available fd value
		
		close(fd[0]);         // Closing read end
		
		execl("/bin/ls", "-l", NULL);
	}
	else {
		close(0);             // Closing Standard Input
		dup(fd[0]);           // Duplicating file descriptor with lowest available fd vlaue
		
		close(fd[1]);         // Closing write end
		execl("/usr/bin/wc", "wc", NULL);
	}
	
}
