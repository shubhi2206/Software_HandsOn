#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sysmacros.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


int main(int args, char argv[]){
	struct stat buf;
	char mtime[100];
	
	stat("file1.txt", &buf);
	printf("INODE of file = %ld \n", buf.st_ino);
	printf("Hard links of file = %ld \n", buf.st_nlink);
	printf("User ID of file = %u \n", buf.st_uid);
	printf("Group Id of file = %d \n", buf.st_gid);
	printf("Size of file = %ld \n", buf.st_size);
	printf("Block Size of file = %ld \n", buf.st_blksize);
	printf("Number of blocks of file = %ld \n", buf.st_blocks);
	printf("Time of last modification = %s \n", ctime(&buf.st_mtime));
	printf("Time of last access = %s \n", ctime(&buf.st_atime));
	printf("Time of file creation = %s \n", ctime(&buf.st_ctime));
	
	return 0;

}
