#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
	int file;
	char buf[10];
	long int val;
	float temp;
	char *filename = "/sys/class/hwmon/hwmon0/temp1_input";

	while (1) {
		if ((file = open(filename, O_RDONLY)) < 0) {
			perror("Failed to open the temperature input file");
			return 1;
		}

		if (read(file, buf, sizeof(buf)) < 0) {
			perror("Failed to read from the temperature input file");
			close(file);
			return 1;
		}

		close(file);

		val = strtol(buf, NULL, 10);
		temp = val / 1000.0;
		printf("Temperature: %.3f°C\n", temp);

		sleep(1);
	}

	return 0;
}

