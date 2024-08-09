#Cross-compiler prefix for ARM
CC :=  arm-linux-gnueabihf-gcc
 
# Build target
obj-m += pcd_platform_driver2.o
obj-m += pcd_platform_driver3.o

PWD :=$(CURDIR)
 
# Default target
all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux M=$(PWD) modules
 
# Clean rule
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux  M=$(PWD) clean
