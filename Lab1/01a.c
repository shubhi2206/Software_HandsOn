
// Program to create Soft Link using symlink()

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int f1 = creat("file1_a.txt", 0644);
	const char target[] = "./file1_a.txt";
	const char path[] = "./sftlink.txt";
	
	//Soft Link Creation
	
	int soft_link = symlink(target,path);
	if (soft_link)
			perror("symlink");
	printf("SymLink File created! \n");
	return 0;
} 
