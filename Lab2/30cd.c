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
	key_t shm_key = ftok("sample.c", 68);                            // Generate a key for IPC
	int shm_id = shmget(shm_key, 1024, IPC_CREAT | 0744);                  // SHM ID
	printf("SHM ID: %d\n", shm_id);
	data = shmat(shm_id, 0, 0);
	
	int detach = shmdt(data);                                       // Detaching SHM created
		if(detach == -1)
			printf("SHM Error:");
		else
			printf("SHM Detached successfully!\n");
	int r = shmctl(shm_id, IPC_RMID, NULL);                        // Removing SHM
		if(r == -1)
			printf("SHM Error:");
		else
			printf("SHM removed successfully!\n");
	return 0;
}
