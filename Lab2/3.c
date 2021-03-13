/* 
	Write a program to set (any one) system resource limit. Use setrlimit system call.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(int agrc, int const argv[]){
	struct rlimit r_limit, r1;
	int ret = getrlimit(RLIMIT_FSIZE, &r_limit);   //maximum size in bytes of files that the process may create
	if(ret == 0){
		printf("FSIZE LIMIT:\nSoft limit: %ld\t Hard limit: %ld\n", r_limit.rlim_cur, r_limit.rlim_max);
	}
	 else
	 	perror("Error: ");
	 	
	 r_limit.rlim_cur = 2048;                        // Setting soft limit
	 //r_limit.rlim_max = 4096;                        // Setting hard limit
	 printf("Setting a 2K file size limit...\n");
	 setrlimit(RLIMIT_FSIZE, &r_limit);
	 getrlimit(RLIMIT_FSIZE, &r1);
	 printf("FSZIE LIMIT:\nSoft limit: %lu\t Hard limit: %lu\n", r1.rlim_cur, r1.rlim_max);
	 return 0;
}
