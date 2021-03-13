

#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int sig_num){
	printf("SIGPROF no : %d is caught!\nTIMER STOPPED\n", sig_num);
	exit(0);
}


int main(){
	signal(SIGPROF, alarm_handler);
		
	struct itimerval delay;
	delay.it_value.tv_sec = 5;
	delay.it_value.tv_usec = 0;
	delay.it_interval.tv_sec = 0;
	delay.it_interval.tv_usec = 0;
	
	int ret = setitimer(ITIMER_PROF, &delay, NULL);
	if(ret == -1){
			perror("Settimer");

		}
	while(1);
	exit(EXIT_SUCCESS);
	
}
