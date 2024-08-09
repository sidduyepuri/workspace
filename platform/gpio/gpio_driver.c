#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/gpio/consumer.h>

#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt, __func__

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Yepuri Siddu"); 
MODULE_DESCRIPTION("A gpio sysfs driver");

/*Device private data structure */
struct gpiodev_private_data
{ 
	char label[20];
	struct gpio_desc *desc;
};

/* Driver private data structures */
struct gpiodrv_private_data {
	int total_devices;
	struct class *class_gpio;
};

struct gpiodrv_private_data gpio_drv_data;

int gpio_sysfs_remove(struct platform_device *pdev)
{
        return 0;
}

int gpio_sysfs_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev>dev;
	const char *name;
	
	int ret;

	//parent device node 
	struct device_node *parent = pdev->dev.of_node;
	struct device_node *child = NULL;
	struct gpiodev_private_data *dev_data;

	for_each_available_child_of_node(parent,child)
	{
		int i = 0;
		dev_data = devm_kzalloc(dev,sizeof(*dev_data), GFP_KERNEL);
		if(!dev_data){
			dev_err(dev, "Cannot allocate memory\n");
			return -ENOMEM;
		}
		if(of_property_read_string(child, "label", &name))
		{
			dev_warn(dev, "Missing label information\n");
			snprintf(dev_data->label,sizeof(dev_data->label), "unkngpio%d", i);
		}
		else{
			strcpy(dev_data->label,name);
			dev_info(dev,"GPIO label=%s\n",dev_data->label);
		}
		dev_data->desc = devm_fwnode_get_gpiod_from_child(dev, "bone", &child->fwnode,GPIOD_ASIS, dev_data->label);
		if(IS_ERR( dev_data->desc)){
			ret = PTR_ERR(dev_data->desc);
			if(ret ==-ENOENT)
				dev_err(dev, "No GPIO has been assigned to the requested function and/or index\n");
			return ret;
		}

		// set the gpio direction to output 	
		ret = gpiod_direction_output(dev_data->desc,0);
		if(ret){
			dev_err(dev, "gpio direction set failed \n");
			return ret;
		}
		i++;
	}
}

struct of_device_id gpio_device_match[] =
{
	{.compatible = "org, bone-gpio-sysfs"},
	{}
};

struct platform_driver gpiosysfs_platform_driver = {
	.probe = gpio_sysfs_probe,
	.remove = gpio_sysfs_remove,
	.driver = {
		.name = "bone-gpio-syfs",
		.of_match_table = of_match_ptr(gpio_device_match)
	}
};

int __init gpio_sysfs_init(void)
{
	gpio_drv_data.class_gpio = class_create(THIS_MODULE, "bone_gpios"); 
	if(IS_ERR(gpio_drv_data.class_gpio)){
		pr_err("Error in creating class \n"); 
		return PTR_ERR(gpio_drv_data.class_gpio);
	}
	platform_driver_register(&gpiosysfs_platform_driver);
	pr_info("module load success\n");
	return 0;
}

void __exit gpio_sysfs_exit(void)
{
	class_destroy(gpio_drv_data.class_gpio);
	platform_driver_unregister(&gpiosysfs_platform_driver);

}

module_init(gpio_sysfs_init);
module_exit(gpio_sysfs_exit);
