#include<linux/module.h>
#include<linux/sysfs.h>
#include<linux/kobject.h>
#include<linux/slab.h>

#include<linux/string.h>

static struct kobject *kernel_object;
static int number;
static const char attribute_name[] = "number";

static ssize_t number_show(struct kobject *kernel_object, struct attribute *attribute, char *buffer)
{
	return sprintf(buffer,"%d\n",number);
}

static ssize_t number_store(struct kobject *kernel_object, struct attribute *attribute, const char *buffer, size_t count)
{
	sscanf(buffer,"%d",&number);
	return count;
}

static struct sysfs_ops operations = {
	.show = number_show,
	.store = number_store,
};

static void number_release(struct kobject *kernel_object)
{
	kfree(kernel_object);
	pr_notice(" res. activated!\n");
}

static struct attribute number_attribute = {
	.name = attribute_name,
	.mode = 0600
};

static struct attribute *attributes[] = {
	&number_attribute,
	NULL
};

static struct kobj_type ktype =
{
	.release = number_release,
	.sysfs_ops = &operations,
	.default_attrs = attributes,
};

static int __init sysfs_test_init(void)
{
	kernel_object = (struct kobject *)kmalloc(sizeof(struct kobject),GFP_KERNEL);
	if(IS_ERR(kernel_object))
		goto err1;
	memset(kernel_object,0,sizeof(struct kobject));
	kobject_init(kernel_object,&ktype);
	if(kobject_add(kernel_object,&THIS_MODULE->mkobj.kobj,"test%d",2))
		goto err2;

	return 0;
err2:
	kfree(kernel_object);
	kernel_object = NULL;
err1:
	pr_alert("Error adding a kobject\n");
	return -ENOMEM;
}

static void __exit sysfs_test_exit(void)
{
	if(kernel_object)
		kobject_put(kernel_object);
}
module_init(sysfs_test_init);
module_exit(sysfs_test_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("sysfs 2.");
