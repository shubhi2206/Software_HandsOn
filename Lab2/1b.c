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
	struct timeval tv = {10, 10};
	struct timeval tv1 = {0, 0};
	struct itimerval delay;                 //Send Signal
	int ret;
	
	delay.it_value = tv;
	delay.it_interval = tv1;
	printf("Timer started for 10 seconds....\n");
	ret = setitimer(ITIMER_VIRTUAL, &delay, 0);  // Decrements only when process is excuting , SIGALM activated upon expiration!
	if(ret){
			perror("Settimer");
			return 0;
	}
	sleep(5);
	while(1){};
	return 0;
}
