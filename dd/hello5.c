#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	
#include <linux/cdev.h>	
#include <linux/device.h>	
#include <linux/delay.h>	
#include <linux/fs.h>	

int base_minor=0;
char *device_name = "mychardev";
int count=1;
dev_t  dev_num;

MODULE_LICENSE("GPL");
static struct class *class;
static struct device *device;

static int test_hello5_init(void)
{
	//dev1 = MKDEV(200,1);
	//dev2 = MKDEV(200,2);
	class=class_create(THIS_MODULE,"myclass5");
	if(!alloc_chrdev_region(&dev_num,base_minor,count,device_name)){
		printk("Device number registerd\n");
		printk("Major number received:%d\n",MAJOR(dev_num));
		device=device_create(class,NULL,dev_num,NULL,device_name);
	}
	else
		printk("Device number not regestered\n");
	return 0;
}

static void test_exit(void)
{
	unregister_chrdev_region(dev_num,count);
	device_destroy(class,dev_num);
	class_destroy(class);
	printk("Device unloaded\n");
}

module_init(test_hello5_init);
module_exit(test_exit);
