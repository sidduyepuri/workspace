#Cross-compiler prefix for ARM
CC :=  arm-linux-gnueabihf-gcc
 
# Build target
obj-m += pcd_sysfs.o
pcd_sysfs-objs += pcd_platform_driver_sysfs.o pcd_syscalls.o

PWD :=$(CURDIR)
 
# Default target
all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux M=$(PWD) modules
 
# Clean rule
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux  M=$(PWD) clean
