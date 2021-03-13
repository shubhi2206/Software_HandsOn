#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char *buffer = "";
	char *file_name = (char *) calloc(100, sizeof(char));
	printf("Enter the name of the file\n");
	scanf("%s", file_name);
	
	int fd = open(file_name, O_RDONLY | O_CREAT);
	
	if(fd != -1){
		char c;
		while( read(fd, &c, 1) == 1){
			write(1, &c, 1);
			if(c == '\n'){
				write(1, "New line encountered\n", 22);
			}
		}
	}
	else {
		perror("Error:");
	}
	printf("\n");
	return 0;
}

// Execute the program with supplying file_8.txt as input
