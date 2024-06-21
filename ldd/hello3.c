#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	
#include <linux/fs.h>	


int base_minor=0;
char *device_name = "mychardev";
int count=1;
dev_t  dev_num;

module_param(base_minor,int,0);
module_param(count,int,0);
module_param(device_name,charp,0);

MODULE_LICENSE("GPL");
static int test_hello1_init(void)
{
	printk("Device loaded\n");
	printk("Minor number :%d\n",MINOR(dev_num));
	printk("count :%d\n",count);
	printk("device name :%s\n",device_name);

	if(!alloc_chrdev_region(&dev_num,base_minor,count,device_name)){
		printk("Device number registered\n");
		printk("Major number received:%d\n",MAJOR(dev_num));
	}
	else
		printk("Device number registered failed\n");
	return 0;
}

static void test_exit(void)
{
	unregister_chrdev_region(dev_num,count);
	printk("Device unloaded\n");
}

module_init(test_hello1_init);
module_exit(test_exit);
