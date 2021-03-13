/*	
	Write a program to create a message queue and print the key and
	message queue id.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main(int agrc, int const argv[]){
	int msg_id;
	key_t msg_key;
	msg_key = ftok(".", 68);                                     // Generate a key for IPC
	msg_id = msgget(msg_key, IPC_CREAT | IPC_EXCL | 0744);       // Message queue ID after creation of Message queue
	if(msg_id == -1)
		perror("MSG_Queue:");
	else
		printf("Key value : %d\nMessage Queue ID : %d\n", msg_key, msg_id );
	
}
