/* 
	Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
	identify all the process related information in the corresponding proc directory.
*/

#include <stdio.h> 
#include <unistd.h>
#include <time.h> 

int main(){
	while(1){
	
	}
}

/* 
	Compile the program, execute as <./a.out &> to get pid
	Run cat /proc/<pid>/status | head 
	The details of the process are as:
	
	Name:	a.out
	Umask:	0002
	State:	R (running)
	Tgid:	18026
	Ngid:	0
	Pid:	18026
	PPid:	16991
	TracerPid:	0
	Uid:	1000	1000	1000	1000
	Gid:	1000	1000	1000	1000

*/
