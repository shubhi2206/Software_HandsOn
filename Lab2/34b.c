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
#include <pthread.h>

void *connection_handler(void *nsd){
	int new = *(int*)nsd;
	char buff[100];
	write(1, "Connected to client...\n", sizeof("Connected to client...\n"));
	write(new, "Connected to server...\n", sizeof("Connected to server...\n"));
	read(new, buff, sizeof(buff));
	printf("Message from the client : %s\n", buff);
	return 0;
}

int main(int agrc, int const argv[]){
	
	int soc_id, nsd, c_length;
	pthread_t threads;
	struct sockaddr_in server, client;
	soc_id = socket(AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(6768);
	
	bind(soc_id, (struct sockaddr *)&server, sizeof(server));
	listen(soc_id, 5);
	
	write(1, "Waiting for client....\n", sizeof("Waiting for client....\n"));
	while(1){
		c_length = sizeof(client);
		nsd = accept(soc_id, (struct sockaddr *)&client, &c_length);
		
		if(pthread_create(&threads, NULL, connection_handler, (void*) &nsd ) < 0){
			perror("Thread creation error:");
			return 1;
		}
	}
	pthread_exit(NULL);
	close(soc_id);
	return 0;
}
