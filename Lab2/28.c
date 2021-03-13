/* 
	Write a program to change the exiting message queue permission. (use msqid_ds structure)
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <time.h>

int main(int agrc, int const argv[]){
	struct ipc_perm msg_perm;
	struct msqid_ds msg_info;
	
	key_t msg_key = ftok("sample.c", 6767);                            // Generate a key for IPC
	int msg_id = msgget(msg_key, IPC_CREAT | IPC_EXCL | 0744);       // Message queue ID after creation of Message queue
	msgctl(msg_id, IPC_STAT, &msg_info);
	msg_perm = msg_info.msg_perm;
	//printf("MSGQ ID: %d\n", msg_id );
	printf("Access Permissions before change : %03o \n", msg_perm.mode & 0777);
	
	msg_perm.mode = 0644 & 0777;
	msgctl(msg_id, IPC_SET, &msg_info);
	printf("Access Permissions after change : %03o \n", msg_perm.mode & 0777);
}
	
