#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEADDRESS 0xe5b00000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int hello_init(void)
{
	if(!request_mem_region(MY_BASEADDRESS,LENGTH,"myports")) {
		pr_info("request mem region failed for myports\n");
	}
	else {
		pr_info("request mem region success for myports\n");
	}
	return 0;
}
static void hello_exit(void)
{
	release_mem_region(MY_BASEADDRESS,LENGTH);
}
module_init(hello_init);
module_exit(hello_exit);

