#obj-m +=char_dev.o
#obj-m +=char_dev_ex1.o
#obj-m +=char_device.o
obj-m += character.o
PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
