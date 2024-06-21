#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	
#include <linux/fs.h>	

int major_number = 120;
int minor_number = 0;
char *device_name = "mychardev";
int count=1;
dev_t  dev_num;

module_param(major_number,int,0);
module_param(minor_number,int,0);
module_param(count,int,0);
module_param(device_name,charp,0);

MODULE_LICENSE("GPL");
static int test_hello1_init(void)
{
	printk("Device loaded\n");
	dev_num = MKDEV(major_number,minor_number);
	printk("Major number :%d\n",MAJOR(dev_num));
	printk("Minor number :%d\n",MINOR(dev_num));
	printk("count :%d\n",count);
	printk("device name :%s\n",device_name);

	if(!register_chrdev_region(dev_num,count,device_name))
		printk("Device number registered\n");
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
