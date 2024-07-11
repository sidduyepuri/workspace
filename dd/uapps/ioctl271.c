#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/ioctl.h>
#include "ioctl_cmd1.h"
int main()
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i=0;
	
	fd = open("/dev/ioctl271",O_RDWR);
	if( fd < 0 )
	{
		perror("open");
		exit(2);
	}

	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	perror("ioctl");
	printf("Length:%u\n",length);
	
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek( fd, 0, SEEK_SET);
	perror("lseek");
	length = read( fd, buffer, 1024);
	perror("Read");
	buffer[1023]='\0';
	printf("Buffer:%s\n",buffer);
	close(fd);
	return 0;
}
