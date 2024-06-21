//heap memory writing to device

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MY_DEVICE "/dev/loopbackdev"

int main()
{
	int retval,user_val=100,k_val;
	char *buffer=malloc(10*sizeof(char));
	pid_t pid;	
	
	printf("opening file:%s\n",MY_DEVICE);
	sleep(2);
	int fd=open(MY_DEVICE,O_RDWR);
	if(fd<0)
	{
		perror("open fail");
		return -1;
	}
	strcpy(buffer,"hello");

	getchar();
	retval=write(fd,&buffer,sizeof(buffer));
	if(retval<=0){
		perror("open fail");
		return -1;
	}
	printf("written %d bytes\n",retval);

	getchar();
	//retval=read(fd,&user_buffer,sizeof(user_struct));	
	//printf("ret val:%d \tint i:%d \tchar c:%c\n",retval,user_struct.i,user_struct.c);
	//getchar();
	printf("Closing file\n");
	close(fd);
	
	return 0;
}
