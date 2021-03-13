/*
	Write two programs so that both can communicate by FIFO -Use one two communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	
	
	char buffer_r[100], buffer_w[100];
	
	int fd_r = open("myfifo1", O_RDONLY);
	int fd_w = open("myfifo2", O_WRONLY);
	
	read(fd_r, buffer_r, sizeof(buffer_r));               // Reading from myfifo_1
	printf("The message from Process 1: %s\n",buffer_r);
	
	printf("Enter the message for Process 1:\n");  
	scanf("%[^\n]", buffer_w);                            // Writing into myfifo_2
	write(fd_w, buffer_w, sizeof(buffer_w));  
	
	close(fd_r);
	close(fd_w);
	
	return 0;
	
	
	

}
