/*
	Write a simple program to create a pipe, write to the pipe, read from pipe and display on
	the monitor.
	
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
	if(pipe(fd) == 0){
		char data[] = "Data written into pipe.\n";
		write(fd[1], data, sizeof(data));
		b = read(fd[0], buffer, BUFSIZ);
		printf("Read %d bytes from pipe : %s\n", b, buffer);
	}
	else{
		perror("fork");
               exit(EXIT_FAILURE);
	}
	
	close(fd[0]);
	close(fd[1]);
}
