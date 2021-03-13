/* 
	Write a program to remove message queue.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <time.h>

int main(int agrc, int const argv[]){
	
	key_t msg_key = ftok("sample.c", 12);                            // Generate a key for IPC
	int msg_id = msgget(msg_key, IPC_CREAT | 0744);       // Message queue ID after creation of Message queue
	printf("MSG QUEUE ID : %d\n", msg_id);
	int rem = msgctl(msg_id, IPC_RMID, 0);
	if (rem == -1)
		printf("Removal error:");
	else
		printf("msg queue removal successful\n");
}
