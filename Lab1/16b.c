/*
	Program to implement Mandatory Locking
	b) Read Lock
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main() {
	struct flock lock;
	int fd;
	fd = open("file16a.txt", O_RDWR);
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf("Read Lock Mode:\nEntering the CS:\n");
	int ret = fcntl(fd, F_SETLKW, &lock);
	printf("Inside the CS:\n");
	printf("Press Enter to unlock:\n");
	//printf("Value of lock: %d\n",ret);
	
	getchar();
	printf("Unlocked!\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Lock released!\n ");
	return 0;
}
