#obj-m +=hello1.o
#obj-m +=hello2.o
obj-m +=hello3.o

PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	#make -C /home/siddu/src/linux M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	#make -C /home/siddu/src/linux M=$(PWD) clean
