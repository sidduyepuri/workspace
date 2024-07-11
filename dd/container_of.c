//container of used for private data

#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/kdev_t.h>	
#include <linux/printk.h>	
#include <linux/cdev.h>	
#include <linux/device.h>	
#include <linux/delay.h>	
#include <linux/fs.h>	
#include <linux/uaccess.h>	

#define MAX_DEVICES 5
int base_minor=0;
char *device_name = "mesg";
int count=MAX_DEVICES;
dev_t  dev_num;

static struct class *class=NULL;
static struct device *device=NULL;

#define MAX_SIZE 1024
struct msg_device
{
	struct cdev mycdev;
	char kernel_buffer[MAX_SIZE];
};

static struct msg_device msg_devices[MAX_DEVICES];


MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	struct msg_device *my_device = container_of(inode->i_cdev,struct msg_device, mycdev);
	file->private_data = my_device;
	
	pr_info("%s\n",__func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n",__func__);
	return 0;
}

static ssize_t device_read(struct file *file ,char __user *user_buffer,size_t read_count,loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;
	int buffer_index;
	struct msg_device *my_device = (struct msg_device *)file->private_data;
	
	pr_info("%s read offset:%lld\n",__func__, *offset);
	available_space = MAX_SIZE - *(offset);
	
	if(read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	if(bytes_to_read == 0) {
		pr_err("%s: No available spcae in the buffer for readinf\n",__func__);
		return -ENOSPC;
	}

	if( buffer_index > *offset )
		bytes_to_read = buffer_index - *offset;
	else
		return 0;
	
	bytes_read = bytes_to_read - copy_to_user(user_buffer,my_device->kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: copy to user returned:%d\n",__func__,bytes_to_read);
	
	//update file offset
	*offset  += bytes_read;
	
	return bytes_read;
}

static ssize_t device_write(struct file *file ,const char __user *user_buffer,size_t write_count,loff_t *offset)
{
	int bytes_written;
        int available_space;
        int bytes_to_write;
	int buffer_index;

	struct msg_device *my_device = (struct msg_device *)file->private_data;
        pr_info("%s write offset:%lld\n",__func__, *offset);
        available_space = MAX_SIZE - *(offset);

        if(write_count < available_space)
                bytes_to_write = write_count;
        else
                bytes_to_write = available_space;
        
	if(bytes_to_write == 0) {
                pr_err("%s: No available spcae in the buffer for writing\n",__func__);
                return -ENOSPC;
        }

        bytes_written = bytes_to_write - copy_from_user( my_device->kernel_buffer+(*offset), user_buffer, bytes_to_write);
        strcat(my_device->kernel_buffer," ");
	pr_info("%s: Bytes written:%d\n",__func__,bytes_written);
        pr_info("%s: Kernel buffer:%s\n",__func__,my_device->kernel_buffer);

        //update file offset
        *offset  += bytes_written;
	buffer_index += bytes_written;
	
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
    loff_t new_pos = 0;

    switch(orig) {
        case 0: /* seek set */
            new_pos = offset;
            break;
        case 1: /* seek cur */
            new_pos = file->f_pos + offset;
            break;
        case 2: /* seek end */ 
            new_pos = MAX_SIZE - offset;
            break;
    }
    if (new_pos > MAX_SIZE)
        new_pos = MAX_SIZE;
    if (new_pos < 0)
        new_pos = 0;
    file->f_pos = new_pos;
    return new_pos;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek
};

static int test_hello5_init(void)
{
	int i;
	class=class_create(THIS_MODULE,"myclass251");
	if(!alloc_chrdev_region(&dev_num,base_minor,count,device_name)){
		int major = MAJOR(dev_num);
		printk("Device number registerd\n");
		printk("Major number received:%d\n",major);
		
		for(i=0 ;i < MAX_DEVICES;i++) {
			dev_t tmp_device = MKDEV(major,i);
			device=device_create(class,NULL,tmp_device,NULL,"%s%d",device_name,i);
			cdev_init(&msg_devices[i].mycdev,&device_fops);
			msg_devices[i].mycdev.owner = THIS_MODULE;
			cdev_add(&msg_devices[i].mycdev,dev_num,count);
		}
	}
	else
		printk("Device number not regestered\n");
	return 0;
}

static void test_exit(void)
{
	int major = MAJOR(dev_num);
	int i = 0;
	dev_t tmp_device;
	for(i = 0; i< MAX_DEVICES; i++) {
		tmp_device = MKDEV(major, i);
		device_destroy(class,tmp_device);
		cdev_del(&msg_devices[i].mycdev);
	}
	class_destroy(class);
	unregister_chrdev_region(dev_num, count);
	printk("Driver unloaded\n");
}

module_init(test_hello5_init);
module_exit(test_exit);
