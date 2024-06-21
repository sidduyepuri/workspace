#obj-m +=hello1.o
#obj-m +=hello2.o
#obj-m +=hello3.o
#obj-m +=hello4.o
#obj-m +=hello5.o
#obj-m +=hello6.o
#obj-m +=hello6a.o
obj-m +=hello6b.o


PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
