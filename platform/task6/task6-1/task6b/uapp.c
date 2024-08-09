#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define DEVICE_NAME "/dev/mydevice"
int main()
{
	int fd;
	int retval;
	char buffer[10];
	printf("opening File: %s\n",DEVICE_NAME);
	fd = open(DEVICE_NAME,O_RDWR);
	if(fd<0)
	{
		perror("open:");
		return 0;
	}
	retval = write(fd,"hello",5);
	getchar();
	printf("write retval: %d\n",retval);
	retval = write(fd,"hello",5);
	printf("write retval: %d\n",retval);
	close(fd);
	fd = open(DEVICE_NAME,O_RDWR);
	retval = read(fd,buffer,10);
	printf("retval: %s\n",buffer);
	close(fd);
}

