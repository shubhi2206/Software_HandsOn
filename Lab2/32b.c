/* 
	Write a program to implement semaphore to protect any critical section.
	a. rewrite the ticket number creation program using semaphore
	b. protect shared memory from concurrent write access
	c. protect multiple pseudo resources ( may be two) using counting semaphore
	d. remove the created semaphore
*/
                          // run 32b_sem.c for semaphore creation
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include<fcntl.h>


int main(int agrc, int const argv[]){

	key_t sem_key = ftok(".", 110);                            // Generate a key for IPC
	struct sembuf buffer = {0, -1, 0};
	int sem_id = semget(sem_key, 1, 0);  
	printf("Before entering the Critical Section...\n");
	printf("Waiting for unlock...\n");
	
	semop(sem_id, &buffer, 1);                                           //Locking the CS
	printf("Inside the critical section....\n");
	
	char* data;                           
	int shm_id = shmget(sem_key, 1024, IPC_CREAT | 0744);                  // SHM ID
	data = shmat(shm_id, 0, 0);
	printf("Enter the data: ");
	scanf("%[^\n]", data);                                                 // Writing data into SHM
	
	
	printf("Enter to unlock...\n");
	getchar();
	getchar();
	buffer.sem_op = 1;
	semop(sem_id, &buffer, 1);                                          //Unlocking CS
	
	return 0;
}
