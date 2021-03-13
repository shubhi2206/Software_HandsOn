/* 
	Write a program to send messages to the message queue. Check $ipcs -q
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>
#include <string.h>

int main(int agrc, int const argv[]){

	struct msg {
		long int mtype;
		char text[100];
	}msg_buf;
	
	key_t msg_key = ftok("./sample.c", 70);                          // Generate a key for IPC
	int msg_id = msgget(msg_key, IPC_CREAT | 0744);       // Message queue ID after creation of Message queue
	printf("Enter the mtype: ");
	scanf("%ld", &msg_buf.mtype);
	printf("Enter the message :");
	scanf(" %[^\n]", msg_buf.text);
	msgsnd(msg_id, &msg_buf, strlen(msg_buf.text)+1, 0);	
}
