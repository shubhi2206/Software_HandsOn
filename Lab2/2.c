/* 
	Write a program to print the system resource limits. Use getrlimit system call.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(int agrc, int const argv[]){
	struct rlimit r_limit;
	int ret = getrlimit(RLIMIT_MSGQUEUE, &r_limit);                          // Extracting  Limit
	if(ret == 0){
		printf("MSGQUEUE LIMIT:\nSoft limit: %lu\t Hard limit: %lu\n", r_limit.rlim_cur, r_limit.rlim_max);
	}
	 else
	 	perror("Error: ");
	 return 0;
}
