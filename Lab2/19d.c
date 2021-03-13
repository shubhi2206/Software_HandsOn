/*19.
	 Create a FIFO file by
	a. mknod command
	b. mkfifo command
	c. use strace command to find out, which command (mknod or mkfifo) is better.
	c. mknod system call
	d. mkfifo library function

*/

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main(){
	int fifo_file = mknod("fifo1", S_IFIFO | 0774, 0);
	if(fifo_file==0)
		printf("Fifo created!\n FIFO number : %d\n", fifo_file);
	else
		perror("Error: ");
		
	return 0;
}
