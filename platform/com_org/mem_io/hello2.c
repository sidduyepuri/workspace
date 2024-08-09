#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <asm/io.h>

#define MY_BASEADDRESS 0xe5b00000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int hello2_init(void)
{
	if(!request_mem_region(MY_BASEADDRESS,LENGTH,"myports")) {
		pr_info("request mem region failed for myports\n");
	}
	else {
		void __iomem *p;
	
		pr_info("request mem region success for myports\n");
		
		p = ioremap(MY_BASEADDRESS,LENGTH);
		pr_info("ioremap returned:%px\n", p);
		iounmap(p);
	}
	return 0;
}
static void hello2_exit(void)
{
	release_mem_region(MY_BASEADDRESS,LENGTH);
}
module_init(hello2_init);
module_exit(hello2_exit);
