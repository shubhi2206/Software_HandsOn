 /* Write a program to get maximum and minimum real time priority. */
 #define _GNU_SOURCE
 #include<stdio.h>
 #include<sched.h>
 
 int main(int argc, char const *argv[]){
 	int min = sched_get_priority_min(SCHED_FIFO);
 	int max = sched_get_priority_max(SCHED_FIFO);
 	
 	printf("Maximum Priority for FIFO: %d\nMinimum Priority for FIFO: %d\n", min,max);
 }
