//sample code for creating a region
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/ioport.h>

#define MY_BASEPORT 0X00B1
#define NUMBER_PORTS 3

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if(!request_region(MY_BASEPORT, NUMBER_PORTS, "myports")) {
		pr_info("Failed : port in use\n");
	} else {
		pr_info("Success : port allocated\n");
	}
	return 0;
}

static void mod_exit(void)
{
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);
