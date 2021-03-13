/* 
	Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	char c;
	ssize_t no;
	
	
	int f1 = open("file7_copy.txt", O_RDONLY);
	int f2 = open("file7_paste.txt",O_CREAT | O_RDWR | O_TRUNC, 0744);

	while(read(f1,&c,1) == 1)
		write(f2,&c,1);
	close(f1);
	close(f2);

	
}
