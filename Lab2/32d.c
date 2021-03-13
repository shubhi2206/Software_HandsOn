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

int main(int agrc, int const argv[]){
	
	key_t sem_key = ftok("sample.c", 71);                            // Generate a key for IPC
	int sem_id = semget(sem_key, 1, IPC_CREAT | IPC_EXCL | 0744);   
	
	int i = semctl(sem_id, 0, SETVAL, 1);
	
	printf("SEM ID : %d\n", sem_id);
	
	int r = semctl(sem_id, 0, IPC_RMID, 1);
	if(r == -1)
		printf("SEM Error:");
	else
		printf("SEM removed successfully!\n");
	
}
