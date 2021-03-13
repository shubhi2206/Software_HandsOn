/*
	Write two programs so that both can communicate by FIFO -Use two way communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	int fd1 = mkfifo("myfifo1", 0755);            // Creating two pipes
	int fd2 = mkfifo("myfifo2", 0755);
	char buffer_r[100], buffer_w[100];
	
	int fd_w = open("myfifo1", O_WRONLY);
	int fd_r = open("myfifo2", O_RDONLY);
	
	printf("Enter the message for Process 2:\n");  
	scanf("%[^\n]", buffer_w);                           
	write(fd_w, buffer_w, sizeof(buffer_w));             // Writing into myfifo_1
	
	read(fd_r, buffer_r, sizeof(buffer_r));               // Reading from myfifo_2
	printf("The message from Process 2: %s\n",buffer_r);
	
	
	close(fd_r);
	close(fd_w);
	return 0;
	
}
