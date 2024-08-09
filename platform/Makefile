obj-m +=pcd_device_setup3.o
obj-m +=pcd_platform_driver3.o


PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
