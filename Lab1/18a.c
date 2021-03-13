/*
	Program to implement Mandatory Locking
	a) Write Lock
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main() {
	//struct flock lock;
	int fd;
	fd = open("file18.txt", O_RDWR);
	char c4[20]  = "Updated Line.\n";
	int size = 20, choice;
	printf("Enter the record to be modified(1, 2, 3): \n");
	scanf("%d",&choice);
	struct flock lock;
		
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = ((choice -1)*20) + 1;
	lock.l_len = 20;
	lock.l_pid = getpid();
	
	printf("Write Lock Mode:\n");
	fcntl(fd, F_SETLKW, &lock);
	
	printf("Inside the CS\n");
	
	lseek(fd, ((choice -1 )*20), SEEK_SET);
	write(fd, c4, 20);
	
	printf("Press Enter to unlock\n");
	getchar();
	getchar();
	
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
		
	printf("Unlocked!\n");	
}
