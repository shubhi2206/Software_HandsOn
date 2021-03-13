/* 
	Write a program to simulate online ticket reservation. Implement write lock
	Write a program to open a file, store a ticket number and exit. Write a separate program, to
	open the file, implement write lock, read the ticket number, increment the number and print
	the new ticket number then close the file. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "17_ticketstruct.c"

int main(){
	
	int fd;
	int t = 0;
	fd = open("db.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(fd, &t, sizeof(int));
	close(fd);
	return 0;
	 
}

