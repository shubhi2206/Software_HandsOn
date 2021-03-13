/*	
	Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
	a. access permission
	b. uid, gid
	c. time of last message sent and received
	d. time of last change in the message queue
	d. size of the queue
	f. number of messages in the queue
	g. maximum number of bytes allowed
	h. pid of the msgsnd and msgrcv
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>

int main(int agrc, int const argv[]){
	struct ipc_perm msg_perm;
	struct msqid_ds msg_info;
	
	key_t msg_key = ftok("./sample.c", 70);       // Generate a key for IPC  (used same key as 26.c for seeing changes)
	int msg_id = msgget(msg_key, 0777);       // Message queue ID after creation of Message queue
	msgctl(msg_id, IPC_STAT, &msg_info);
	msg_perm = msg_info.msg_perm;
	

	printf("Access Permissions : %03o \n", msg_perm.mode & 0777);  
	printf("UID : %d \n", msg_perm.uid);
 	printf("Gid : %d\n", msg_perm.gid);
	printf("Time of last message sent: %s\n", ctime(&msg_info.msg_stime));
	printf("Time of last message received: %s\n", ctime(&msg_info.msg_rtime));
	printf("Time of last change in message queue: %s\n", ctime(&msg_info.msg_ctime));
	printf("Size of the message queue : %lu\n", msg_info.msg_qnum);
	printf("Number of the messages in the queue : %lu\n", msg_info.msg_qbytes);
	printf("Maximum number of bytes allowed : %lu\n", msg_info.msg_cbytes);
	printf("PID of msgsnd : %d\n", msg_info.msg_lspid);
	printf("PID of msgrcv : %d\n", msg_info.msg_lrpid);
		
	
}
