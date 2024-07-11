//copy_to_user

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MY_DEVICE "/dev/msg10"

int main()
{
	int retval,user_val=100,k_val;
	char buffer[10];
	pid_t pid;	
	
	printf("opening file:%s\n",MY_DEVICE);
	sleep(2);
	int fd=open(MY_DEVICE,O_RDWR);
	if(fd<0)
	{
		perror("open fail");
		return -1;
	}
	
	retval = write(fd,"hello",5);
	printf("write retval:%d\n",retval);
	getchar();
	
	retval = write(fd,"hello",5);
	printf("write retval:%d\n",retval);
	getchar();
	
	printf("closing file\n");
	close(fd);
	return 0;
}
