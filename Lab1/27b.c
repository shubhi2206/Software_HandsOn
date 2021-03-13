/* 
	27. Write a program to execute ls -Rl by the following system calls
	a. execl
	b. execlp
	c. execle
	d. execv
	e. execvp
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char const *argv[]){

	execlp("ls", "ls", "-Rl", NULL); 
	//name of the program to run will be taken from filename specified or system will search for program file in PATH variable.
	
}
