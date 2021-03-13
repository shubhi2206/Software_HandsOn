/* 
	Write a program to create five new files with infinite loop. Execute the program in the background
	and check the file descriptor table at /proc/pid/fd.
*/

#include <fcntl.h>           
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int count = 1;
	int fd;
	while(1){
		if(count >=1 && count <= 5){
			const char file[10] = "file_5.txt";
			fd  = creat(file, S_IRWXU);
			printf("File Descriptor value: %d\n", fd);
			count++;
		}   
	}
	return 0;
}

/* 
	Compile and execute the program as ./a.out & to retrieve the Process ID.
	Check the details in the /proc/pid/fd
	
	cd /proc/6297/fd
	shubh@shubh-Lenovo-G50-70:/proc/6297/fd$ ls
	0  1  2  3  4  5  6  7
	shubh@shubh-Lenovo-G50-70:/proc/6297/fd$ 

	
	
*/
