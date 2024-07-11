#obj-m +=hello1.o
#obj-m +=hello2.o
#obj-m +=hello3.o
#obj-m +=hello4.o
#obj-m +=hello5.o
#obj-m +=hello6.o
#obj-m +=hello6a.o
#obj-m +=hello6b.o
#obj-m +=hello10.o
#obj-m +=hello241.o
#obj-m +=hello242.o
#obj-m +=hello243.o
obj-m +=hello244.o
#obj-m +=hello251.o
#obj-m +=container_of.o
#obj-m +=ioctl251.o
#obj-m +=ioctl271.o
#obj-m +=atomic.o
#obj-m +=access_ok.o

PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
