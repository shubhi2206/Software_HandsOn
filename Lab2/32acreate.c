#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(){
	
	int fd;
	int t = 0;
	fd = open("file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(fd, &t, sizeof(int));
	close(fd);
	return 0;
	 
}

