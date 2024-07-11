#include "pcd_platform_driver_sysfs.h"

struct of_device_id org_pcdev_dt_match[]; 
/*configuration data of the driver for devices */
struct device_config pcdev_config[] = 
{
	[PCDEVA1X] = {.config_item1 = 60, .config_item2 = 21},
	[PCDEVB1X] = {.config_item1 = 61, .config_item2 = 22},
	[PCDEVC1X] = {.config_item1 = 62, .config_item2 = 23},
	[PCDEVD1X] = {.config_item1 = 63, .config_item2 = 24},
	[PCDEVE1X] = {.config_item1 = 64, .config_item2 = 25},
};

/*Driver's private data */
struct pcdrv_private_data pcdrv_data;
 
/* file operations of the driver */
struct file_operations pcd_fops=
{
	.open = pcd_open,
	.release = pcd_release,
	.read = pcd_read,
	.write = pcd_write,
	.llseek = pcd_lseek,
	.owner = THIS_MODULE
};
/*create 2 variables of struct device_attributes */
 
 
/*Called when the device is removed from the system */
int pcd_platform_driver_remove(struct platform_device *pdev)
{
	struct pcdev_private_data  *dev_data = dev_get_drvdata(&pdev->dev);
 
	/*1. Remove a device that was created with device_create() */
	device_destroy(pcdrv_data.class_pcd,dev_data->dev_num);
	/*2. Remove a cdev entry from the system*/
	cdev_del(&dev_data->cdev);
 
	pcdrv_data.total_devices--;
	dev_info(&pdev->dev,"A device is removed\n");
 
	return 0;
}
struct pcdev_platform_data* pcdev_get_platform_from_dt(struct device *dev)
{
	struct device_node *dev_node = dev->of_node;
	struct pcdev_platform_data *pdata;
	
	if(!dev_node)
		/* this probe didn't happen because of device tree node */
		return NULL;
	pdata = devm_kzalloc(dev,sizeof(*pdata),GFP_KERNEL);
	if(!pdata){
		dev_info(dev,"Cannot allocate memory\n");
		return ERR_PTR(-ENOMEM);
	}
	if(of_property_read_string(dev_node,"org,device-serial-num",&pdata->serial_number)){
		dev_info(dev,"Missing serial number property\n");
		return ERR_PTR(-EINVAL);
	}
	if(of_property_read_u32(dev_node,"org,size",&pdata->size)){
		dev_info(dev,"Missin size property\n");
		return ERR_PTR(-EINVAL);
	}
	if(of_property_read_u32(dev_node,"org,perm",&pdata->perm)){
		dev_info(dev,"Missing perm property\n");
		return ERR_PTR(-EINVAL);
	}

	return pdata;
} 
/*Called when matched platform device is found */
int pcd_platform_driver_probe(struct platform_device *pdev)
{
	int ret;
 
	struct pcdev_private_data *dev_data;
 
	struct pcdev_platform_data *pdata;
	
	struct device *dev = &pdev->dev;
	const struct of_device_id *match;

	int driver_data;

	dev_info(dev,"A device is detected\n");
	match = of_match_device(of_match_ptr(org_pcdev_dt_match),dev);

	if(match){
		pdata = pcdev_get_platform_from_dt(dev);

		if(IS_ERR(pdata))	
			return -EINVAL;
		driver_data = (int)match->data;
	}
	else {
		pdata = (struct pcdev_platform_data*)dev_get_platdata(dev);
		driver_data =pdev->id_entry->driver_data;
	}
	if(!pdata)
	{
			dev_info(dev,"No platform data available\n");	
			return -EINVAL;
	}
	/*else
	{
		//match = of_match_device(pdev->dev.driver->of_match_table,&pdev->dev);
		//driver_data = (int)match->data;	
		//shortcut(By using kernels helpers function)
		driver_data = (int)of_device_get_match_data(dev);
	}*/
 
	/*Dynamically allocate memory for the device private data  */
	dev_data = devm_kzalloc(dev, sizeof(*dev_data),GFP_KERNEL);
	if(!dev_data){
		dev_info(dev,"Cannot allocate memory \n");
		return -ENOMEM;
	}
 
	/*save the device private data pointer in platform device structure */
	dev_set_drvdata(dev,dev_data);
 
	dev_data->pdata.size = pdata->size;
	dev_data->pdata.perm = pdata->perm;
	dev_data->pdata.serial_number = pdata->serial_number;
 
	dev_info(dev,"Device serial number = %s\n",dev_data->pdata.serial_number);
	dev_info(dev,"Device size = %d\n", dev_data->pdata.size);
	dev_info(dev,"Device permission = %d\n",dev_data->pdata.perm);
 
	dev_info(dev,"Config item 1 = %d\n",pcdev_config[driver_data].config_item1 );
	dev_info(dev,"Config item 2 = %d\n",pcdev_config[driver_data].config_item2 );
 
 
	/*Dynamically allocate memory for the device buffer using size 
	information from the platform data */
	dev_data->buffer = devm_kzalloc(dev,dev_data->pdata.size,GFP_KERNEL);
	if(!dev_data->buffer){
		dev_info(dev,"Cannot allocate memory \n");
		return -ENOMEM;
	}
 
	/* Get the device number */
	dev_data->dev_num = pcdrv_data.device_num_base + pcdrv_data.total_devices;
 
	/*Do cdev init and cdev add */
	cdev_init(&dev_data->cdev,&pcd_fops);
	dev_data->cdev.owner = THIS_MODULE;
	ret = cdev_add(&dev_data->cdev,dev_data->dev_num,1);
	if(ret < 0){
		dev_err(dev,"Cdev add failed\n");
		return ret;
	}
 
	/*Create device file for the detected platform device */
	pcdrv_data.device_pcd = device_create(pcdrv_data.class_pcd,NULL,dev_data->dev_num,NULL,"pcdev-%d",pcdrv_data.total_devices);
	if(IS_ERR(pcdrv_data.device_pcd)){
		dev_err(dev,"Device create failed\n");
		ret = PTR_ERR(pcdrv_data.device_pcd);
		cdev_del(&dev_data->cdev);
		return ret;
	}
 
	pcdrv_data.total_devices++;
 
	dev_info(dev,"Probe was successful\n");
	return 0;
 
}
 
struct platform_device_id pcdevs_ids[] = 
{
	[0] = {.name = "pcdev-A1x",.driver_data = PCDEVA1X},
	[1] = {.name = "pcdev-B1x",.driver_data = PCDEVB1X},
	[2] = {.name = "pcdev-C1x",.driver_data = PCDEVC1X},
	[3] = {.name = "pcdev-D1x",.driver_data = PCDEVD1X},
	[4] = {.name = "pcdev-E1x",.driver_data = PCDEVE1X},
	{ } /*Null termination */
};
 
struct of_device_id org_pcdev_dt_match[] = {
	{.compatible = "pcdev-A1x",.data = (void *)PCDEVA1X},
	{.compatible = "pcdev-B1x",.data = (void *)PCDEVB1X},
	{.compatible = "pcdev-C1x",.data = (void *)PCDEVC1X},
	{.compatible = "pcdev-D1x",.data = (void *)PCDEVD1X},
	{.compatible = "pcdev-E1x",.data = (void *)PCDEVE1X},
	{ }
};
struct platform_driver pcd_platform_driver = 
{
	.probe = pcd_platform_driver_probe,
	.remove = pcd_platform_driver_remove,
	.id_table = pcdevs_ids,
	.driver = {
		.name = "mychardev",
		.of_match_table = of_match_ptr(org_pcdev_dt_match)
	} 
};

static int __init pcd_platform_driver_init(void)
{
	int ret;
 
	/*Dynamically allocate a device number for MAX_DEVICES */
	ret = alloc_chrdev_region(&pcdrv_data.device_num_base,0,MAX_DEVICES,"pcdevs");
	if(ret < 0){
		pr_err("Alloc chrdev failed\n");
		return ret;
	}
 
	/*Create device class under /sys/class */
	pcdrv_data.class_pcd = class_create(THIS_MODULE,"pcd_class2");
	if(IS_ERR(pcdrv_data.class_pcd)){
		pr_err("Class creation failed\n");
		ret = PTR_ERR(pcdrv_data.class_pcd);
		unregister_chrdev_region(pcdrv_data.device_num_base,MAX_DEVICES);
		return ret;
	}
 
	/*Register a platform driver */
	platform_driver_register(&pcd_platform_driver);
	pr_info("pcd platform driver loaded\n");
	return 0;
 
}
 
 
static void __exit pcd_platform_driver_cleanup(void)
{
	/*Unregister the platform driver */
	platform_driver_unregister(&pcd_platform_driver);
 
	/*Class destroy */
	class_destroy(pcdrv_data.class_pcd);
 
	/*Unregister device numbers for MAX_DEVICES */
	unregister_chrdev_region(pcdrv_data.device_num_base,MAX_DEVICES);
	pr_info("pcd platform driver unloaded\n");
 
}
 
 
module_init(pcd_platform_driver_init);
module_exit(pcd_platform_driver_cleanup);
 
//module_platform_driver(pcd_platform_driver);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CCL");
MODULE_DESCRIPTION("Platform device driver LKM");
