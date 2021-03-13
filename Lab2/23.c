/*
	Write a program to print the maximum number of files can be opened within a process and
	size of a pipe (circular buffer).
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){

	printf("Size of pipe: %ld\n", pathconf(".",_PC_PIPE_BUF));
	printf("Maximum number of files: %ld\n", sysconf(_SC_OPEN_MAX));
}
