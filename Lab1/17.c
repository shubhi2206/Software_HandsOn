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


int main(){
	struct ticketno{
	int ticket_number;
	} db;
	//struct ticketno db;
	struct flock lock;
	int fd;
	fd = open("db.txt", O_RDWR);
	read(fd, &db, sizeof(db));
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();	
	
	printf("Before entering the Critical Section:\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Current ticket number: %d\n", db.ticket_number);
	db.ticket_number++;
	lseek(fd, 0L, SEEK_SET);
	printf("Inside the Critical Section:\n");
	write(fd,&db, sizeof(db));
	getchar();
	lock.l_type = F_UNLCK;
	printf("Value Updated!\n");
	fcntl(fd,F_SETLK, &lock);
	close(fd);
	
	return 0;
}
