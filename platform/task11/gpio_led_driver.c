#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/io.h>

#define GPIO_LED_PIN 28 // Assuming GPIO1_28
#define GPIO1_BASE_ADDR 0x4804C000
#define GPIO_SIZE 0x00001000

static void __iomem *gpio1_base;
#define GPIO_SETDATAOUT (0x194)
#define GPIO_CLEARDATAOUT (0x190)
#define GPIO_OE (0x134)

static int majorNumber;
static struct class*  gpioClass  = NULL;
static struct device* gpioDevice = NULL;

static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops =
{
	.open = dev_open,
	.write = dev_write,
	.release = dev_release,
};

static int __init gpio_led_init(void) {
	printk(KERN_INFO "GPIO_LED: Initializing the GPIO_LED LKM\n");

	majorNumber = register_chrdev(0, "gpio_led", &fops);
	if (majorNumber<0){
		printk(KERN_ALERT "GPIO_LED failed to register a major number\n");
		return majorNumber;
	}
	printk(KERN_INFO "GPIO_LED: registered correctly with major number %d\n", majorNumber);

	gpioClass = class_create(THIS_MODULE, "gpio");
	if (IS_ERR(gpioClass)){
		unregister_chrdev(majorNumber, "gpio_led");
		printk(KERN_ALERT "Failed to register device class\n");
		return PTR_ERR(gpioClass);
	}
	printk(KERN_INFO "GPIO_LED: device class registered correctly\n");

	gpioDevice = device_create(gpioClass, NULL, MKDEV(majorNumber, 0), NULL, "gpio_led");
	if (IS_ERR(gpioDevice)){
		class_destroy(gpioClass);
		unregister_chrdev(majorNumber, "gpio_led");
		printk(KERN_ALERT "Failed to create the device\n");
		return PTR_ERR(gpioDevice);
	}
	printk(KERN_INFO "GPIO_LED: device class created correctly\n");

	gpio1_base = ioremap(GPIO1_BASE_ADDR, GPIO_SIZE);
	if (!gpio1_base) {
		printk(KERN_ALERT "Failed to remap memory for GPIO\n");
		return -ENOMEM;
	}

	// Set GPIO1_28 as output
	iowrite32(ioread32(gpio1_base + GPIO_OE) & ~(1 << GPIO_LED_PIN), gpio1_base + GPIO_OE);

	return 0;
}

static void __exit gpio_led_exit(void) {
	iowrite32(ioread32(gpio1_base + GPIO_OE) | (1 << GPIO_LED_PIN), gpio1_base + GPIO_OE);
	iounmap(gpio1_base);
	device_destroy(gpioClass, MKDEV(majorNumber, 0));
	class_unregister(gpioClass);
	class_destroy(gpioClass);
	unregister_chrdev(majorNumber, "gpio_led");
	printk(KERN_INFO "GPIO_LED: Goodbye from the LKM!\n");
}

static int dev_open(struct inode *inodep, struct file *filep){
	printk(KERN_INFO "GPIO_LED: Device has been opened\n");
	return 0;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
	char msg;
	copy_from_user(&msg, buffer, len);
	if (msg == '1') {
		iowrite32(1 << GPIO_LED_PIN, gpio1_base + GPIO_SETDATAOUT);
	} else if (msg == '0') {
		iowrite32(1 << GPIO_LED_PIN, gpio1_base + GPIO_CLEARDATAOUT);
	}
	return len;
}

static int dev_release(struct inode *inodep, struct file *filep){
	printk(KERN_INFO "GPIO_LED: Device successfully closed\n");
	return 0;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yepuri Siddu");
MODULE_DESCRIPTION("A simple Linux char driver for GPIO LED");
MODULE_VERSION("0.1");

module_init(gpio_led_init);
module_exit(gpio_led_exit);

