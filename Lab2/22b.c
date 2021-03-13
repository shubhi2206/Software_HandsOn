/*
	Write a program to wait for data to be written into FIFO within 10 seconds, use select
	system call with FIFO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	int fd = open("fifo1", O_WRONLY);
	printf("Enter the data to be written: ");               
	char buffer[100];
	scanf("%[^\n]", buffer);
	write(fd, buffer, sizeof(buffer));                     // Writing data to fifo pipe 
	close(fd);
}
