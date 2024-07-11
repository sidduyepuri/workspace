#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x441199c1, "module_layout" },
	{ 0x71eadc8, "cdev_del" },
	{ 0x5f53d92f, "cdev_init" },
	{ 0xa1c0b261, "device_destroy" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1e6d42b5, "__platform_driver_register" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x5f754e5a, "memset" },
	{ 0xc5850110, "printk" },
	{ 0xab27726d, "of_property_read_string" },
	{ 0x3d3e385, "device_create" },
	{ 0x59efa71e, "_dev_err" },
	{ 0x3244653b, "of_match_device" },
	{ 0xc663131e, "cdev_add" },
	{ 0xeb0c0578, "_dev_info" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0xebc96d1c, "class_destroy" },
	{ 0x4c5731ee, "platform_driver_unregister" },
	{ 0x16048e29, "of_property_read_variable_u32_array" },
	{ 0x4333ebfe, "devm_kmalloc" },
	{ 0xdcfb973, "__class_create" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
};

MODULE_INFO(depends, "");

