#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
pthread_t thread1, thread2;

void *func(void *arg)
{
	int fd;

	fd = open("/dev/atomic1",O_RDWR);
	if(fd<0)
	{
		perror("open");
		printf("Thread id:%ld failed to opened file\n",pthread_self());
		return 0;
	}
	else
	{
		printf("Thread id:%ld successfully opened file\n",pthread_self());
	}
	sleep(5);
	write(fd,"hello world",sizeof("hello world"));

	close(fd);
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_create(&thread1, 0, func, 0);
	pthread_create(&thread2, 0, func, 0);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	return 0;
}
