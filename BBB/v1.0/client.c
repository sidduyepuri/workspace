/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
sem_t cons,prod;
pthread_t a_thread,b_thread;
char buff[BUFSIZ+1];
char buff2[BUFSIZ+1];
void *client_fun(void *arg);
int server_sockfd, client_sockfd,res;
void *server_fun(void *arg);
int sockfd;

int main()
{
	void *thread_result;
	int len;
	struct sockaddr_in address;
	int result;
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);
	/*  Create a socket for the client.  */

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/*  Name the socket, as agreed with the server.  */

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.28.66.238");
	address.sin_port = 9734;
	len = sizeof(address);

	/*  Now connect our socket to the server's socket.  */

	result = connect(sockfd, (struct sockaddr *)&address, len);

	if(result == -1) {
		perror("oops: client2");
		exit(1);
	}
	printf("server connected\n");
	res = pthread_create(&a_thread, NULL, server_fun, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	/*  We can now read/write to client on client_sockfd.  */

	res = pthread_create(&b_thread, NULL, client_fun, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	/*  We can now read/write to client on client_sockfd.  */
	res =pthread_join(a_thread,&thread_result);
	if(res<0)
	{
		perror("thread join");
		exit(EXIT_FAILURE);
	}
	res =pthread_join(b_thread,&thread_result);
	if(res<0)
	{
		perror("thread join");
		exit(EXIT_FAILURE);
	}
	exit(0);
}
void *client_fun(void *arg)
{
	while(1)
	{
		//   sem_wait(&cons);
		res=read(0,buff2,BUFSIZ);
		res=write(sockfd,buff2,BUFSIZ);
		memset(buff2, '\0', sizeof(buff2));
		// sem_post(&prod);
	}
	pthread_exit("done");
}

void *server_fun(void *arg)
{
	while(1)
	{
		// sem_wait(&prod);
		res=read(sockfd,buff,BUFSIZ);
		write(0,buff,BUFSIZ);
		memset(buff, '\0', sizeof(buff));
		//sem_post(&cons);
	}
	pthread_exit("done");
}
