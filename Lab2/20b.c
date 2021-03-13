/*
	Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	char buffer[100];
	
	printf("Enter the message to be sent to the pipe:\n");  
	scanf("%[^\n]", buffer);
	int fd  = open("myfifo", O_WRONLY);
	write(fd, buffer, sizeof(buffer));                  // Writing to the pipe
	close(fd);
	
	
	

}
