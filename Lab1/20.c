/* Find out the priority of your running program. Modify the priority with nice command. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>



int main(int argc, char const *argv[]){
	int p = getpriority(PRIO_PROCESS, getpid());
	printf("Current priority = %d\n", p);
	
	nice(10);
	
	int q = getpriority(PRIO_PROCESS, getpid());
	printf("Updated priority = %d\n", q);
	 
	
}

