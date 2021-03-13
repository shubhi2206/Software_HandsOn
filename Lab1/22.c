/*
	Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output 	of the file. 
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
	int fd = open("file22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(!fork()){
		char text[] = "This is the Child Process.\n";
		write(fd, text, sizeof(text));	
	}
	else {
	        char text[] = "This is the Parent Process.";
		write(fd, text, sizeof(text));
		
	}
		
	return 0;
}
