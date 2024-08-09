#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/delay.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/printk.h>
#include"header.h"
#include<linux/export.h>

MODULE_LICENSE("GPL");
static struct class *class=NULL;
static struct device *device=NULL;
static struct cdev mycdev;
static int base_minor= 0;
static int count=1;

char *device_name = "mychardev6";
dev_t devicenumber;
abc kernel_struct;
static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s \n",__func__);
	if((file->f_flags & O_ACCMODE)==O_RDONLY)
	{
		pr_info("opened File in Read only mode\n");
	}
	else if((file->f_flags & O_ACCMODE)==O_WRONLY)
	{
		pr_info("opened file for write only");
	}
	else if((file->f_flags & O_ACCMODE)==O_RDWR)
	{
		pr_info("opend for read and write");
	}
	return 0;
}
static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s \n",__func__);
	return 0;
}
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;
	pr_info("%s \n",__func__);

	retval = copy_to_user(user_buffer,&kernel_struct,count);
	pr_info("%d: Kernel buffer %c :\t user buffer: %p\n",__func__, kernel_struct.i,kernel_struct.c,user_buffer);
	return 0;
}
static ssize_t device_write(struct file *file,const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s \n",__func__);
	int retval;
	retval = copy_from_user(&kernel_struct,user_buffer,count);
	pr_info("%s: copy from user returned : %d\n",__func__,retval);
	pr_info("%s:kernl buffer: %d %d \t count: %lu\n offset: %llu",__func__,kernel_struct.i,kernel_struct.c,count,*offset);
	return count;
}
struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_hello6_init(void)
{
	class = class_create(THIS_MODULE,"myclass5");
	if(!alloc_chrdev_region(&devicenumber,base_minor,count,device_name))
	{
		printk("Device number registredn");
		printk("major number recived %d\n",MAJOR(devicenumber));
		device = device_create(class,NULL,devicenumber,NULL, "mydevice");
		cdev_init(&mycdev,&device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev,devicenumber,count);
		printk("Device created\n");
	}
	else
	{
		printk("device unregistred\n");
	}
	return 0;
}
static void test_hello6_exit(void)
{
	unregister_chrdev_region(devicenumber,count);
	device_destroy(class, devicenumber);
	class_destroy(class);
	cdev_del(&mycdev);
	printk("Device destroyed\n");
}
module_init(test_hello6_init);
module_exit(test_hello6_exit);

