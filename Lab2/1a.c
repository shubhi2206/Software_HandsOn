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
	struct itimerval delay;
	int ret;
	
	
	struct timeval tv = {10, 10};
	struct timeval tv1 = {0, 0};
	
	delay.it_value = tv;
	delay.it_interval = tv1;
	printf("Timer started!\n");
	ret = setitimer(ITIMER_REAL, &delay, NULL);      
	if(ret){
			perror("Settimer");
			return 0;
		}
	while(1);
}
