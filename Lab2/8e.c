

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void alarm_handler(int sig_num){
	printf("SIGALRM No: %d is caught!\nTIMER STOPPED\n", sig_num);
	exit(0);
}

int main(){
	signal(SIGALRM, alarm_handler);
	struct timeval tv = {7, 0};
	struct timeval tv1 = {0, 0};
	struct itimerval delay;                 //Send Signal
	int ret;
	
	delay.it_value = tv;
	delay.it_interval = tv1;
	printf("Start Timer for 7 seconds!\n");
	ret = setitimer(ITIMER_REAL, &delay, 0);
	if(ret){
			perror("Settimer");
			return 0;
		}
	//sleep(5);
	while(1){};
	return 0;
}
