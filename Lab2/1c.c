/*
	Write a separate program (for each time domain) to set a interval timer in 10sec and
	10micro second
	a. ITIMER_REAL
	b. ITIMER_VIRTUAL
	c. ITIMER_PROF
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>



int main(){
	struct itimerval delay, delay1;
	int ret;
	
	//signal(SIGALRM, alarm_handler);
	
	delay.it_value.tv_sec = 5;
	delay.it_value.tv_usec = 0;
	delay.it_interval.tv_sec = 0;
	delay.it_interval.tv_usec = 0;
	ret = setitimer(ITIMER_PROF, &delay, NULL);
	if(ret){
			perror("Settimer");
			return 0;
		}
	while(1){};
}
