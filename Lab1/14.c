/*
	Write a program to find the type of a file.
	a. Input should be taken from command line.
	b. program should be able to identify any type of a file.
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sysmacros.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


int main(int args, char *argv[]){
	struct stat buf;
	stat(argv[1], &buf);
	printf("File type: ");

        switch (buf.st_mode & S_IFMT) {
        case S_IFBLK:  printf("Block device\n");            break;
        case S_IFCHR:  printf("Character device\n");        break;
        case S_IFDIR:  printf("Directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("Symlink\n");                 break;
        case S_IFREG:  printf("Regular file\n");            break;
        case S_IFSOCK: printf("Socket\n");                  break;
        default:       printf("unknown?\n");                break;
           }


}
