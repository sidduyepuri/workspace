#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	dev_t dev_num;
	
	printk("Major number :%d\n",MAJOR(dev_num));
	printk("Minor number :%d\n",MINOR(dev_num));
	
	dev_num=49;
	printk("Major number :%d\n",MAJOR(dev_num));
	printk("Minor number :%d\n",MINOR(dev_num));
	
	dev_num=MKDEV(120,30);
	printk("Major number :%d\n",MAJOR(dev_num));
	printk("Minor number :%d\n",MINOR(dev_num));
	return 0;
}

static void test_exit(void)
{
	;
}

module_init(test_hello_init);
module_exit(test_exit);
