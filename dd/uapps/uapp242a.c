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

	retval = write(fd,"hello",5);
	printf("write retval:%d\n",retval);	
	getchar();
	
	retval = write(fd,"world",5);
	printf("write retval:%d\n",retval);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

