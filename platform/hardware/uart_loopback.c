#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main() {
	const char* device_path = "/dev/ttyS2"; // UART2 device path
	int uart_fd = open(device_path, O_RDWR);
	if (uart_fd == -1) {
		perror("Error opening UART");
		return 1;
	}
	const char* msg = "Hello, loopback test!\n";
	write(uart_fd, msg, strlen(msg));
	char received[100];
	read(uart_fd, received, sizeof(received));
	printf("Received: %s", received);
	close(uart_fd);
	return 0;
}

