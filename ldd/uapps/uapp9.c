//copy_to_user

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MY_DEVICE "/dev/mychardev9"
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

	getchar();
	retval=write(fd,&user_val,1);
	if(retval<=0){
		perror("open fail");
		return -1;
	}
	printf("written %d bytes\n",retval);
	
	getchar();
	retval=read(fd,&k_val,1);	
	printf("kernel_value:%d \tread:%d bytes\n",k_val,retval);
	getchar();
	printf("Closing file\n");
	close(fd);
	
	return 0;
}
