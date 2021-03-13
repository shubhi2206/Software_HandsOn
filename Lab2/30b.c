/* 
	Write a program to create a shared memory.
	a. write some data to the shared memory
	b. attach with O_RDONLY and check whether you are able to overwrite.
	c. detach the shared memory
	d. remove the shared memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>

int main(int agrc, int const argv[]){
	char* data; 
	key_t shm_key = ftok("sample.c", 67);                            // Generate a key for IPC
	int shm_id = shmget(shm_key, 1024, 0);                           // SHM ID
	data = shmat(shm_id, 0, SHM_RDONLY);                             
	// SHM_RDONLY does'nt allow to overwrite data and dumps segmentation fault
	printf("Data from the shared memory: %s\n", data);
	printf("Enter the data: ");
	scanf("%[^\n]", data);
	return 0;
}
