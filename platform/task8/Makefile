#obj-m +=ex_code1.o
#obj-m +=ex_code2.o
#obj-m +=task-8a.o
#obj-m +=task-8b.o
obj-m +=task-8c.o
#obj-m +=task8c2.o

PWD :=$(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

