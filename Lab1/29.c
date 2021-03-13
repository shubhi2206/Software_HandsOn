/* */
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sched.h>

int main(int argc, char const *argv[]){
	int pid = 0;
	int policy = sched_getscheduler(pid);
	printf("Current Policy: %d\n", policy);
	
	struct sched_param param;
	param.sched_priority = 99;
	
	sched_setscheduler(pid, SCHED_FIFO, &param);
	int policy1 = sched_getscheduler(pid);
	printf("Updated Policy: %d\n", policy1);
	
	
	return 0;
	
}

