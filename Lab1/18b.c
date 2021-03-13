/*	Write a program to perform Record locking.
	a. Implement write lock
	b. Implement read lock
	Create three records in a file. Whenever you access a particular record, first lock it then modify/access
	to avoid race condition.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	int fd;
	fd = open("file_18.txt", O_RDWR | O_CREAT, 0666);
	struct flock lock;
	
	int input;
	printf("Enter the record(1, 2, 3) to be locked:");
	scanf("%d", &input);
	
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = ((input -1)*20) + 1;
	lock.l_len = 20;
	lock.l_pid = getpid();
		
	printf("Read Lock Mode:\nEntering the CS:\n");
	int ret = fcntl(fd, F_SETLKW, &lock);
	printf("Inside the CS:\n");
	char text[20];
	lseek(fd, ((input -1 )*20), SEEK_SET);
	read(fd, text, sizeof(text));
	printf("Press Enter to unlock:\n");
	
	getchar();
	getchar();
	printf("Unlocked!\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	write(1, text, sizeof(text));
	printf("\nLock released!\n");
	return 0;
		
}	


