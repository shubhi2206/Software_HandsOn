/* 
	Write a program to create a semaphore and initialize value to the semaphore.
	a. create a binary semaphore
	b. create a counting semaphore
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <time.h>

int main(int agrc, int const argv[]){
	//union semun arg;
	key_t sem_key = ftok("sample.c", 68);                            // Generate a key for IPC
	int sem_id = semget(sem_key, 1, IPC_CREAT | IPC_EXCL | 0744);   
	//arg.value = 1;
	int i = semctl(sem_id, 0, SETVAL, 1);
	
	printf("%d\n", i);
}
