#include <stdio.h>
 #include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	fd_set rfds;
        struct timeval tv;
        int ret_time;

        FD_ZERO(&rfds);
        FD_SET(0, &rfds);

           /* Wait up to ten seconds. */
       tv.tv_sec = 10;
       tv.tv_usec = 0;
       ret_time = select(1, &rfds, NULL, NULL, &tv);


       if (ret_time == -1)
       	perror("select()");
       else if (ret_time){
               printf("Data is available now.\n");
               while(getchar() != '\n');
       }
       else
               printf("No data within ten seconds.\n");
	
       return 0;
}


