#obj-m += hello1.o 
#obj-m += hello2.o 
#obj-m += hello3.o 
#obj-m += rtc.o 
#obj-m += rtc2.o 
#obj-m += rtc3.o 
obj-m += kbrd.o 

PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
