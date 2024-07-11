#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include "ioctl2.h"

#define DEVICE_NAME "mydevice"
#define CLASS_NAME "myclass"

static int my_major;
static struct class* my_class = NULL;
static struct device* my_device = NULL;

static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int value;

    switch(cmd) {
        case MY_IOCTL_CMD1:
            printk(KERN_INFO "MY_IOCTL_CMD1 executed\n");
            break;

        case MY_IOCTL_CMD2:
            if (copy_to_user((int __user *)arg, &value, sizeof(value))) {
                return -EFAULT;
            }
            printk(KERN_INFO "MY_IOCTL_CMD2 executed\n");
            break;

        case MY_IOCTL_CMD3:
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT;
            }
            printk(KERN_INFO "MY_IOCTL_CMD3 executed with value %d\n", value);
            break;

        case MY_IOCTL_CMD4:
            if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
                return -EFAULT;
            }
            value *= 2; // Example operation
            if (copy_to_user((int __user *)arg, &value, sizeof(value))) {
                return -EFAULT;
            }
            printk(KERN_INFO "MY_IOCTL_CMD4 executed with new value %d\n", value);
            break;

        default:
            return -EINVAL;
    }

    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = my_ioctl,
    .owner = THIS_MODULE,
};

static int __init my_init(void) {
    my_major = register_chrdev(0, DEVICE_NAME, &fops);
    if (my_major < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return my_major;
    }

    my_class = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(my_class)) {
        unregister_chrdev(my_major, DEVICE_NAME);
        printk(KERN_ALERT "Failed to register device class\n");
        return PTR_ERR(my_class);
    }

    my_device = device_create(my_class, NULL, MKDEV(my_major, 0), NULL, DEVICE_NAME);
    if (IS_ERR(my_device)) {
        class_destroy(my_class);
        unregister_chrdev(my_major, DEVICE_NAME);
        printk(KERN_ALERT "Failed to create the device\n");
        return PTR_ERR(my_device);
    }

    printk(KERN_INFO "Device driver loaded\n");
    return 0;
}

static void __exit my_exit(void) {
    device_destroy(my_class, MKDEV(my_major, 0));
    class_unregister(my_class);
    class_destroy(my_class);
    unregister_chrdev(my_major, DEVICE_NAME);
    printk(KERN_INFO "Device driver unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple example device driver with ioctl");
MODULE_VERSION("0.1");

