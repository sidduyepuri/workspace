//copy_to_user

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mystruct.h"

#define MY_DEVICE "/dev/mychardevf10"

abc user_struct;

int main()
{
	int retval,user_val=100,k_val;
	char buffer[10];
	pid_t pid;	
	abc user_struct={1,'a'};
	
	printf("opening file:%s\n",MY_DEVICE);
	sleep(2);
	int fd=open(MY_DEVICE,O_RDWR);
	if(fd<0)
	{
		perror("open fail");
		return -1;
	}

	getchar();
	retval=write(fd,&user_struct,sizeof(user_struct));
	if(retval<=0){
		perror("open fail");
		return -1;
	}
	printf("written %d bytes\n",retval);

	user_struct.i=2;
	user_struct.c='b';
	
	getchar();
	retval=read(fd,&user_struct,sizeof(user_struct));	
	printf("ret val:%d \tint i:%d \tchar c:%c\n",retval,user_struct.i,user_struct.c);
	getchar();
	printf("Closing file\n");
	close(fd);
	
	return 0;
}
