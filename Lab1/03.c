// Program to create a file using creat()

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int f1 = creat("file3.txt", 0644);
	if(f1)
		printf("File created! \n");
	else
		perror("File Creation ");
	printf("File descriptor value is %d \n", f1);
	return 0;
} 
