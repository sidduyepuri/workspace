obj-m += 6_irqhandle.o

PWD :=$(CURDIR)

all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb_linux/linux M=$(PWD) modules
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/siddu/bbb_linux/linux M=$(PWD) clean
