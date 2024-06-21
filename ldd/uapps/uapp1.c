#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MY_DEVICE "/dev/mychardev6b"
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
	pid=fork();
	if(pid==0)
	{
		printf("child process exrcuting and writting hello world:%ld\n",write(fd,"hello world",sizeof("hello world")));
		exit(0);
	}
	else{
		printf("parent process exrcuting and writting hello embedded:%ld\n",write(fd,"hello embedded",sizeof("hello embedded")));
		wait(0);
		exit(0);
	}
	return 0;
}
