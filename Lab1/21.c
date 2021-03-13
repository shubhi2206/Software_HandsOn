/* Write a program, call fork and print the parent and child process id. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char const *argv[]){
	if(!fork())
		printf("Process ID of Child : %d\n", getpid());
	else
		printf("Process ID of Parent : %d\n", getpid());
		
	return 0;
}
