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
#include <unistd.h>
#include<fcntl.h>
                                // run 32a_sem.c for semaphore creation

typedef struct ticket{
	int ticket_no;
}ticket;

int main(int agrc, int const argv[]){
	int fd = open("file", O_RDWR);
	ticket t;
	key_t sem_key = ftok(".", 100);                            // Generate a key for IPC
	struct sembuf buffer = {0, -1, 0};                               // Decrementing semaphore by -1 whenever we enter into CS
	int sem_id = semget(sem_key, 1, 0);  
	printf("Before entering the Critical Section...\n");
	printf("Waiting for unlock...\n");
	
	semop(sem_id, &buffer, 1);                                       // Locking before entering CS
	printf("Inside the critical section....\n");
	
	read(fd, &t, sizeof(ticket));
	printf("Ticket Number: %d\n", t.ticket_no);
	t.ticket_no += 1;                                                // Incrementing ticket number
	lseek(fd, 0L, SEEK_SET);
	write(fd, &t, sizeof(ticket));                                   // Writing into file
	printf("New Ticket Number: %d\n", t.ticket_no);
	
	printf("Enter to unlock...\n");
	getchar();
	buffer.sem_op = 1;                                               //Incrementing Semaphore for unlocking
	semop(sem_id, &buffer, 1);                                       //Unlocking from CS
	close(fd);
	return 0;
}
