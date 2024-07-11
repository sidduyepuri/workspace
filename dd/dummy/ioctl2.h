#define MY_IOCTL_BASE 'W'
#define MY_IOCTL_CMD1 _IO(MY_IOCTL_BASE, 0) // No arguments
#define MY_IOCTL_CMD2 _IOR(MY_IOCTL_BASE, 1, int) // Read integer
#define MY_IOCTL_CMD3 _IOW(MY_IOCTL_BASE, 2, int) // Write integer
#define MY_IOCTL_CMD4 _IOWR(MY_IOCTL_BASE, 3, int) // Read and write integer

