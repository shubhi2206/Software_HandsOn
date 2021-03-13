/* 
	Write a program to open a file, duplicate the file descriptor and append the file with both the
	descriptors and check whether the file is updated properly or not.
	a. use dup
	b. use dup2
	c. use fcntl
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int fd = open("file11_c.txt", O_CREAT | O_RDWR | O_APPEND, 0744);
	
	int fd_copy = fcntl(fd, F_DUPFD, 0);
	
	char buffer_fd[] = "Text is appended using initial file descriptor\n";
	char buffer_fdcopy[] = "Text is appended using duplicate file descriptor\n";
	
	//printf("%d------%d", fd, fd_copy);
	
	write(fd, buffer_fd, sizeof(buffer_fd));
	
	write(fd_copy, buffer_fdcopy, sizeof(buffer_fdcopy));
	
	
	
}
