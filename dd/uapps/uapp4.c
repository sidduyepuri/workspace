#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MY_DEVICE "/dev/mychardevf4"
int main()
{
	int retval;
	char buffer[10];
	pid_t pid;	
	printf("opening file:%s\n",MY_DEVICE);
	sleep(2);
	int fd=open(MY_DEVICE,O_RDONLY);
	if(fd<0)
	{
		perror("open fail");
		return -1;
	}
	close(fd);
	
	getchar();
	fd=open(MY_DEVICE,O_WRONLY);
        if(fd<0)
        {
                perror("open fail");
                return -1;
        }
        close(fd);
	
	getchar();
        fd=open(MY_DEVICE,O_RDWR);
        if(fd<0)
        {
                perror("open fail");
                return -1;
        }
        close(fd);


	return 0;
}
