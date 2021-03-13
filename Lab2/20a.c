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
	int fd = mkfifo("myfifo", 0744);                 // Creating pipe using mkfifo
	char buffer[100];
	int fd1 = open("myfifo", O_RDONLY);
	read(fd1, buffer, sizeof(buffer));               // Reading from pipe
	printf("The message from the pipe: %s\n",buffer);
	close(fd1);
	return 0;
	
}
