#Cross-compiler prefix for ARM
CC :=  arm-linux-gnueabihf-gcc
 
# Build target
#obj-m += pcd_device_setup.o
#obj-m += pcd_platform_driver.o
obj-m += pcd_device_setup3.o
#obj-m += pcd_platform_driver3.o
#obj-m += hello.o

PWD :=$(CURDIR)
 
# Default target
all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux M=$(PWD) modules
	#make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux-4.19.94-ti-r42/linux M=$(PWD) modules
 
# Clean rule
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux M=$(PWD) clean
	#make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb/linux-4.19.94-ti-r42/linux M=$(PWD) clean
