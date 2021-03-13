/* 
	Write a program to create three child processes. The parent should wait for a particular child (use
	waitpid system call).
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>




int main(int argc, char const *argv[]){
	int pid_1, pid_2, pid_3, status;
	pid_1 = fork();
	if(pid_1 == 0){
		// Child 1 is executed when fork returns 0
		sleep(2);
		printf("Child[1] ID : %d\n Parent ID : %d\n", getpid(), getppid());
		// First Child Process details are printed
	}
	else {
		pid_2 = fork();
		if(pid_2 == 0){
			sleep(4);
			printf("Child[2] ID : %d\n Parent ID : %d\n", getpid(), getppid());
			
		} 
		else {
			pid_3 == fork();
			if(pid_3 == 0){
				sleep(6);
				printf("Child[3] ID : %d\n Parent ID : %d\n", getpid(), getppid());
				// Third child also gets executed before the second child
				
			}
			else {
				waitpid(pid_1, NULL, 0);
				printf("Waited Parent ID: %d\n", getpid());
			}
		}
	}
	
}
