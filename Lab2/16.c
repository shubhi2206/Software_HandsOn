/*
	Write a program to send and receive data from parent to child vice versa. Use two way
	communication.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){

	int fd1[2], fd2[2], b;
	pipe(fd1);
	pipe(fd2);
	char buffer[BUFSIZ + 1];
	char buffer1[BUFSIZ + 1];
	if(!fork()){
		close(fd1[0]);                                   // Closing unused ends of pipe
		close(fd2[1]);
		printf("Enter the data for Parent:\n");          // Child Process for entering data 
		scanf("%[^\n]", buffer);
		write(fd1[1], buffer, BUFSIZ);
		
		read(fd2[0], buffer1, BUFSIZ);                    // Child Process for reading data from parent 
		printf("Data read from parent: %s\n", buffer1);
	}
	else {
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], buffer, BUFSIZ);                     // Parent Process for reading data
		printf("Data read from child: %s\n", buffer);       
		
		printf("Enter the data for Child :\n");
		scanf("%[^\n]", buffer1);
		
		write(fd2[1], buffer1, BUFSIZ);                   // Parent Process for entering data
			
	}
	
	
	return 0;
	
}
