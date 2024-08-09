#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>

static struct kobject *kernel_object;
static int number;

static ssize_t number_show(struct kobject *kernel_object, struct kobj_attribute *attribute, char *buffer) {
    return sprintf(buffer, "%d\n", number);
}

static ssize_t number_store(struct kobject *kernel_object, struct kobj_attribute *attribute, const char *buffer, size_t count) {
    sscanf(buffer, "%d", &number);
    return count;
}

static struct kobj_attribute number_kattribute = __ATTR(number, 0664, number_show, number_store);

static int __init sysfs_test_init(void) {
    kernel_object = kobject_create_and_add("test", NULL);
    if (!kernel_object) {
        printk(KERN_ALERT "Could not create a kobject!\n");
        return -ENOMEM;
    }

    if (sysfs_create_file(kernel_object, &number_kattribute.attr)) {
        kobject_put(kernel_object);
        printk(KERN_ALERT "Could not create a sysfs file!\n");
        return -ENOMEM;
    }

    printk(KERN_INFO "Sysfs entry created successfully in /sys\n");
    return 0;
}

static void __exit sysfs_test_exit(void) {
    if (kernel_object) {
        sysfs_remove_file(kernel_object, &number_kattribute.attr);
        kobject_put(kernel_object);
    }
}

module_init(sysfs_test_init);
module_exit(sysfs_test_exit);
MODULE_DESCRIPTION("sysfs.");
MODULE_LICENSE("GPL");

