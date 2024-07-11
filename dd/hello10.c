//offset

#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	
#include <linux/cdev.h>	
#include <linux/device.h>	
#include <linux/delay.h>	
#include <linux/fs.h>	
#include <linux/uaccess.h>	

int base_minor=0;
char *device_name = "msg10";
int count=1;
dev_t  dev_num;

static struct class *class=NULL;
static struct device *device=NULL;
static struct cdev mycdev;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n",__func__);
	file->f_ops = 0;
        buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n",__func__);
	return 0;
}

static ssize_t device_read(struct file *file ,char __user *user_buffer,size_t read_count,loff_t *offset)
{
	int retval;
	pr_info("%s read offset:%lld\n",__func__,*offset);
	if(buffer_index + read_count > MAX_SIZE) {
		pr_err("%s: buffer_index:%d\t read_count:%lu\t Max size:%d\n",__func__,buffer_index,read_count,MAX_SIZE);
		return -ENOSPC;
	}
	retval = copy_to_user(user_buffer,kernel_struct+*offset,read_count;
        pr_info("%s: copy to user returned:%d\n",__func__,retval);
        
	*offset += read_count;
	return read_count;	
}

static ssize_t device_write(struct file *file ,const char __user *user_buffer,size_t write_count,loff_t *offset)
{
	int retval;

        pr_info("%s write offset:%lld\n",__func__,*offset);
        if(buffer_index + write_count > MAX_SIZE) {
                pr_err("%s: buffer_index:%d\t read_count:%lu\t Max size:%d\n",__func__,buffer_index,write_count,MAX_SIZE);
                return -ENOSPC;
        }
        retval = copy_from_user(kernel_buffer+buffer_index,user_buffer,write_count;
        pr_info("%s: copy from user returned:%d\n",__func__,retval);
        pr_info("%s kernel buffer:%s\n",__func__,kernel_buffer);
	
	buffer_index += write_count;
	*offset += write_count;
	return write_count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_hello5_init(void)
{
	class=class_create(THIS_MODULE,"myclass10");
	if(!alloc_chrdev_region(&dev_num,base_minor,count,device_name)){
		printk("Device number registerd\n");
		printk("Major number received:%d\n",MAJOR(dev_num));
		device=device_create(class,NULL,dev_num,NULL,device_name);
		cdev_init(&mycdev,&device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev,dev_num,count);
	}
	else
		printk("Device number not regestered\n");
	return 0;
}

static void test_exit(void)
{
	unregister_chrdev_region(dev_num,count);
	cdev_del(&mycdev);
	device_destroy(class,dev_num);
	class_destroy(class);
	printk("Driver unloaded\n");
}

module_init(test_hello5_init);
module_exit(test_exit);
