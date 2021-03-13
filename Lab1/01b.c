
// Program to create Soft Link using symlink()
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int f1 = open("file1_a.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	const char target[] = "./file1_a.txt";
	const char path[] = "./hardlink.txt";
	
	//Hard Link Creation
	
	int hard_link = link(target,path);
	if (! hard_link)
		printf("Hard link created \n");
	else
		perror("Link");
	//printf("%d \n",hard_link);
	close(f1);
	return 0;
} 
