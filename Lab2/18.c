/*
	Write a program to find out total number of directories on the pwd.
	execute ls -l | grep ^d | wc ? Use only dup2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);
	
	if(!fork()){
		close(1);             
		dup2(fd1[1], 1);       
		
		close(fd1[0]);
		close(fd2[1]);
		close(fd2[0]);         
		
		execl("/bin/ls", "ls", "-l", NULL);
	}
	else {
		if(!fork()){
			close(0);
			dup2(fd1[0],0);
			close(fd1[1]);
			close(1);
			dup2(fd2[1], 1);
			close(fd2[0]);	
			
			execl("/usr/bin/grep", "grep", "^d", NULL);
			
		}
		else {
			close(0);
			dup2(fd2[0], 0);
			close(fd2[1]);
			close(fd1[0]);
			close(fd1[1]);
			
			execl("/usr/bin/wc", "wc", "-l", NULL);
		}
		
	}
	
	
}
