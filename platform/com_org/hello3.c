//sample code for creating a region
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/ioport.h>
#include<linux/delay.h>
#include<asm/io.h>

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	outb(0x03,0x0061); //Enabling speaker
	ssleep(10);
	outb(0x00,0x0061); //Disabling speaker
	return 0;
}

static void mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);
