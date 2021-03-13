/* 
	Write a program to implement semaphore to protect any critical section.
	a. rewrite the ticket number creation program using semaphore
	b. protect shared memory from concurrent write access
	c. protect multiple pseudo resources ( may be two) using counting semaphore
	d. remove the created semaphore
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <time.h>
						 // run 32c_sem.c for semaphore creation
int main(int agrc, int const argv[]){
	struct sembuf buffer = {0, -1, 0};
	key_t sem_key = ftok("sample.c", 50);                            // Generate a key for IPC
	int sem_id = semget(sem_key, 1, 0);
	
	
	printf("Before entering the Critical Section.....\n");
	semop(sem_id, &buffer, 1);  
	printf("Inside CS....\nPress Enter to exit....\n");
	getchar();
	buffer.sem_op = 1;
	semop(sem_id, &buffer, 1);
	printf("Outside the CS.....\n");
	
	return 0;
}
	
	
