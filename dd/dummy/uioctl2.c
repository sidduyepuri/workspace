#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define MY_IOCTL_BASE 'W'
#define MY_IOCTL_CMD1 _IO(MY_IOCTL_BASE, 0)
#define MY_IOCTL_CMD2 _IOR(MY_IOCTL_BASE, 1, int)
#define MY_IOCTL_CMD3 _IOW(MY_IOCTL_BASE, 2, int)
#define MY_IOCTL_CMD4 _IOWR(MY_IOCTL_BASE, 3, int)

int main() {
    int fd = open("/dev/mydevice", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    int value = 42;
    if (ioctl(fd, MY_IOCTL_CMD3, &value) < 0) {
        perror("ioctl");
        close(fd);
        return -1;
    }

    if (ioctl(fd, MY_IOCTL_CMD4, &value) < 0) {
        perror("ioctl");
        close(fd);
        return -1;
    }
    printf("New value: %d\n", value);

    close(fd);
    return 0;
}

