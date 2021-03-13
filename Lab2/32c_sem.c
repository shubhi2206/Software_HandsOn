/*
	Creating semaphore for 32c.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <time.h>

int main(int agrc, int const argv[]){
	//union semun arg;
	key_t sem_key = ftok("sample.c", 50);                            // Generate a key for IPC
	int sem_id = semget(sem_key, 1, IPC_CREAT | IPC_EXCL | 0744);   
	//arg.value = 1;
	int i = semctl(sem_id, 0, SETVAL, 2);
	
	printf("%d\n", i);
}
