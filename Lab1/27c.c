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

	char *const env[] = {"PATH=/bin:/usr/bin", "TERM=console", 0};
	execle("/bin/ls", "ls", "-Rl", NULL, env); 
	
	
}
