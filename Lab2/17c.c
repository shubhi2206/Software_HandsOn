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

int main(int agrc, int const argv[]){
	int fd[2];
	pipe(fd);
	
	if(!fork()){
		close(1);                                   // Closing stdout
		fd[1] = fcntl(fd[1], F_DUPFD, 1);           //Creation of duplicate stdout
		close(fd[0]);
		
		execl("/bin/ls", "ls", "-l", NULL);
	}
	else {
		close(0);                                  // Closing stdin
		fd[0] = fcntl(fd[0], F_DUPFD, 0);          // Creation of duplicate stdin
		close(fd[1]);
		execl("/usr/bin/wc", "wc", NULL);
	}
	
}
