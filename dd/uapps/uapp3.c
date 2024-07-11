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
	getchar();
	printf("Process2 executing and writting hello world:%ld\n",write(fd,"hello world",sizeof("hello world")));
	printf("closing file2\n");
	return 0;
}
