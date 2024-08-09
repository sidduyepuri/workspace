#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_MITIGATION_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x85bd1608, "__request_region" },
	{ 0x122c3a7e, "_printk" },
	{ 0xde80cd09, "ioremap" },
	{ 0x848d372e, "iowrite8" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xedc03953, "iounmap" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x77358855, "iomem_resource" },
	{ 0xb98e8027, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "247AB63789E4FA0EE0DD9FB");
