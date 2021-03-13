/*
	Write a program to find out the opening mode of a file. Use fcntl.
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int fd = open("file11_c.txt", O_RDWR | O_APPEND);
	
	int fd_copy = fcntl(fd , F_GETFL);
	
	int accmode = fd_copy & O_ACCMODE;
	
    	if (accmode == 0)   
    		printf("File is opened in read only mode. \n");
    	else if (accmode == 1)   
    		printf("File is opened in write only mode. \n");
    	else if (accmode == 2)     
    		printf("File is opened in read write mode. \n");
    	else printf("unknown access mode");
		
	close(fd);
}
