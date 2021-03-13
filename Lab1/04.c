/* 
	Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	
	int f1 = open("file_4.txt", O_RDONLY| O_CREAT | O_EXCL, 0444);
	// For the first time, it'll create the file, however when we execute the
	// same object file again, it'll return error status.
	if(f1 == -1)
		perror ("File ");	
	return 0;
} 
