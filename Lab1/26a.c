/* 
	Write a program to execute an executable program.
	a. use some executable program
	b. pass some input to an executable program. (for example execute an executable of $./a.out name)
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

	execl("./file_26","Hello World", NULL);
	
}

// Run as ./a.out file26

