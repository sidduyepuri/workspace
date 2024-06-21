#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
	int fd;
	char option;
	
	printf("demo program started\n");
	
	fd=open("/dev/mychardev6b",O_RDWR);
	if(fd<0){
		perror("open fails\n");
		return 0;
	}
	while(1){
		printf("****please enter your option****");
		printf("	1.write		\n");
		printf("	2.read		\n");
		printf("	3.Exit		\n");
		scanf(" %c",&option);
		
		switch(option)
		{
			case '1': printf("Enter string to insert into the driver\n");
				  scanf(" %[^\n]s",write_buf);
				  printf("Data written...\n");
				  write(fd,write_buf,sizeof(write_buf)+1);
				  printf("Done...\n");
				  break;
			case '2': printf("Data is reading\n");
                                  read(fd,read_buf,sizeof(write_buf)+1);
                                  printf("Done...\n");
                                  printf("Data = %s\n\n",read_buf);
                                  break;
			case '3': close(fd);
				  exit(1);
				  break;
			default: printf("Enter valid option \n");
				 break;

		}
	}
	close(fd);
	return 0;
}
