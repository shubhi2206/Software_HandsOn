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
	int f = mkfifo("fifo1", 0755);
	int fd = open("fifo1", O_NONBLOCK | O_RDONLY);
	char buffer[100];
	fd_set rfds;
        struct timeval tv;
        int ret_time;
	FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

       tv.tv_sec = 10;
       tv.tv_usec = 0;
       ret_time = select(4, &rfds, NULL, NULL, &tv);


       if (ret_time == -1)
       	perror("select()");
       else if (ret_time){
       	printf("Data is available within 10 seconds!\n");
               read(fd, buffer, sizeof(buffer));
               printf("Data: %s\n", buffer);
               
       }
       else
               printf("No data within ten seconds.\n");
	close(fd);	
       return 0;
}
