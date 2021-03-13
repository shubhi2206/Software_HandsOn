/* 
	Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
*/

#include <stdio.h> 
#include <unistd.h>
#include <time.h> 

int main(){
	clock_t t; 
   	t = clock(); 
    	getpid(); 
    	t = clock() - t; 
    
    	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    	printf("getpid() took %f seconds to execute \n", time_taken); 
    	return 0; 

}
