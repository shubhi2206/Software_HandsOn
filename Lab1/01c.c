// Program to create FIFO Link using mknod()

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

#define FIFO_FILE "MYFIFO"

int main(){
	
	//FIFO file Creation
	
	int fd = mknod(FIFO_FILE, S_IFIFO, 0644);
	printf("fd = %d\n", fd);
	
	return 0;
} 
