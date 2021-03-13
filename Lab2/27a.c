/* 
	Write a program to receive messages from the message queue.
	a. with 0 as a flag
	b. with IPC_NOWAIT as a flag
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>
#include <string.h>

int main(int agrc, int const argv[]){
	struct msqid_ds msg_info;
	struct buffer {
		long int mtype;
		char text[100];
	}msg_buf;
	 // Generate a key for IPC (Here I used same key as 26.c for extracting messages)
	key_t msg_key = ftok("./sample.c", 70);                  
	int msg_id = msgget(msg_key, IPC_CREAT | 0744);       // Message queue ID after creation of Message queue
	printf("Enter the mtype from which message is to extracted: ");
	scanf("%ld", &msg_buf.mtype);
	int rcv = msgrcv(msg_id, &msg_buf, sizeof(msg_buf.text), msg_buf.mtype, 0);
	if(rcv == -1)
		perror("msgrcv: ");
	else
		printf("Message type: %ld\nMessage received: %s\n", msg_buf.mtype, msg_buf.text);
	
	return 0;		
}
