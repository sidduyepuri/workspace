#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MY_DEVICE "/dev/mychardevf6"
int main()
{
	int retval;
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

	getchar();
	retval=write(fd,"hello",sizeof("hello"));
	if(retval<=0){
		perror("open fail");
		return -1;
	}

	getchar();
	printf("written %d bytes\n",retval);
	retval=read(fd,buffer,sizeof(buffer));
	
	printf("read %d bytes\n",retval);
	getchar();
	printf("Closing file\n");
	close(fd);
	
	return 0;
}
