/*
	Write a program to communicate between two machines using socket.
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
	char buffer[100], result;
	soc_id = socket(AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(6768);
	connect(soc_id, (struct sockaddr *)&server, sizeof(server));
	
	read(soc_id, buffer, sizeof(buffer));
	printf("%s\n", buffer);
	write(1, "...Write to the server:\n", sizeof("...Write to the server:\n"));
	scanf("%[^\n]", buffer);
	write(soc_id, buffer, sizeof(buffer));
	
	close(soc_id);
	return 0;
	
}
