/*
	Write a simple program to send some data from parent to the child process.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	int fd[2], b;
	char buffer[BUFSIZ + 1];
	char buffer1[BUFSIZ + 1];
	if(pipe(fd) == 0){
		if(!fork()){
			close(fd[1]);                                // Reading in Child Process
			
			read(fd[0], buffer1, BUFSIZ);
			printf("Data read from parent: %s\n", buffer1);
		}
		else {
			close(fd[0]);                               // Writing from Parent Process
			printf("Enter the data to be written:\n");
			scanf("%[^\n]", buffer);
			write(fd[1], buffer, BUFSIZ);
		}
	}
	else{
		perror("fork");
               exit(EXIT_FAILURE);
	}
	
	close(fd[0]);
	close(fd[1]);
}
