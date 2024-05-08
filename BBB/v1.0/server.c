/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t cons,prod;
pthread_t a_thread,b_thread;
char buff[BUFSIZ+1];
char buff2[BUFSIZ+1];
void *server_fun(void *arg);
void *client_fun(void *arg);
int server_sockfd, client_sockfd,res;
int main()
{

	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);
	void *thread_result;
	/*  Create an unnamed socket for the server.  */

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/*  Name the socket.  */

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("172.28.66.238");
	server_address.sin_port = 9734;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	/*  Create a connection queue and wait for clients.  */

	listen(server_sockfd, 5);

	client_len = sizeof(client_address);
	printf("searching for client\n");
	client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);
	printf("client connected\n");

	res = pthread_create(&a_thread, NULL, client_fun, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	/*  We can now read/write to client on client_sockfd.  */
	res = pthread_create(&b_thread, NULL, server_fun, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_join(a_thread,&thread_result);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_join(b_thread,&thread_result);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("threads joined\n");
	exit(0);
}
void *server_fun(void *arg)
{
	while(1)
	{
		//sem_wait(&prod);
		// res=read(0,buff,BUFSIZ);
		fgets(buff2,1024,stdin);
		write(client_sockfd,buff2,BUFSIZ);
		memset(buff2, '\0', sizeof(buff2));
		//sem_post(&cons);
	}
}
void *client_fun(void *arg)
{
	while(1)
	{
		// sem_wait(&cons);
		res=read(client_sockfd,buff,BUFSIZ);
		// printf(" read %d\n",res);
		write(0,buff,BUFSIZ);
		memset(buff, '\0', sizeof(buff));
		// sem_post(&prod);
	}
}
