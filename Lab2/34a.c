/*
	Write a program to create a concurrent server.
	a. use fork
	b. use pthread_create
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <fcntl.h>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(int agrc, int const argv[]){
	struct sockaddr_in server, client;
	int soc_id, nsd, c_length;
	char buffer[100];
	soc_id = socket(AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(6768);
	
	bind(soc_id, (struct sockaddr *)&server, sizeof(server));
	listen(soc_id, 1);
	
	write(1, "...Waiting for client....\n", sizeof("...Waiting for client....\n"));
	while(1){
		c_length = sizeof(client);
		nsd = accept(soc_id, (struct sockaddr *)&client, &c_length);
		write(1, "...Connected to client...\n", sizeof("...Connected to client...\n"));
		if(!fork()){
			close(soc_id);
			write(nsd, "...Connected to server...\n", sizeof("...Connected to server...\n"));
			read(nsd, &buffer, sizeof(buffer));
			printf("Message from the client : %s\n", buffer);
			exit(0);
		}
		else{
			close(nsd);
		}
	
	}
}
