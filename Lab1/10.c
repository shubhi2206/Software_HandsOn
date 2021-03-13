#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int f1 = open("file10.txt", O_CREAT | O_RDWR | O_TRUNC );
	off_t cursor;
	write(f1, "Hello world!",13);
	cursor = lseek(f1, 10, SEEK_END);
	printf("Cursor position at %ld \n", cursor);
	
	char buffer[] = "Sample test!";
	write(f1, buffer, sizeof(buffer));
        
	close(f1);
	return 0;
	

}
