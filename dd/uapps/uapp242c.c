#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define DEVICE_FILE "/dev/msg242"

int main()
{
	int retval;
	char buffer[10];
	int i;
	
	printf("opening file:%s \n",DEVICE_FILE);
	int fd = open(DEVICE_FILE,O_RDWR);
	if(fd<0) {
		perror("open fails");
		exit(1);
	}
	getchar();

	retval = read(fd,buffer,5);
	printf("read retval:%d\n",retval);
	buffer[retval]='\0';
	printf("read buffer:%s\n",buffer);	
	getchar();
	
	retval = read(fd,buffer,5);
	printf("read retval:%d\n",retval);
        buffer[retval]='\0';
	printf("read buffer:%s\n",buffer);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

