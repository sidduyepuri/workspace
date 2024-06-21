#obj-m +=fops1.o
#obj-m +=fops4.o
#obj-m +=fops6.o
#obj-m +=fops7.o
#obj-m +=fops8.o
#obj-m +=fops9.o
#obj-m +=fops10.o
#obj-m +=fops11.o
obj-m +=fops12.o
#obj-m +=loopback.o


PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
