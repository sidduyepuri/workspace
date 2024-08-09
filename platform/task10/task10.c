#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/pagemap.h>
#include <linux/slab.h>
#include <linux/time.h>

#define SIMPLEFS_MAGIC 0x10032013

static struct inode *simplefs_make_inode(struct super_block *sb, int mode)
{
    struct inode *inode = new_inode(sb);

    if (inode) {
        inode->i_ino = get_next_ino();
        inode_init_owner(&init_user_ns, inode, NULL, mode);
        inode->i_atime = inode->i_mtime = inode->i_ctime = current_time(inode);
    }
    return inode;
}

static void simplefs_put_super(struct super_block *sb)
{
    printk(KERN_INFO "simplefs: super block destroyed\n");
}

static struct super_operations const simplefs_super_ops = {
    .put_super = simplefs_put_super,
};

static int simplefs_create( struct user_namespace *ns, struct inode *dir, struct dentry *dentry, umode_t mode, bool excl)
{
    struct inode *inode = simplefs_make_inode(dir->i_sb, mode);
    int error = -ENOSPC;

    if (inode) {
        d_instantiate(dentry, inode);
        dget(dentry);   /* Extra count - pin the dentry in core */
        error = 0;
    }
    return error;
}

static struct dentry *simplefs_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
    struct inode *inode = NULL;
    d_add(dentry, inode);
    return NULL;
}

static int simplefs_mkdir( struct user_namespace *ns,struct inode *dir, struct dentry *dentry, umode_t mode)
{
    struct inode *inode = simplefs_make_inode(dir->i_sb, mode | S_IFDIR);
    int error = -ENOSPC;

    if (inode) {
        inode->i_op = &simple_dir_inode_operations;
        inode->i_fop = &simple_dir_operations;
        d_instantiate(dentry, inode);
        dget(dentry);   /* Extra count - pin the dentry in core */
        error = 0;
    }
    return error;
}

static struct inode_operations simplefs_dir_inode_operations = {
    .create = simplefs_create,
    .lookup = simplefs_lookup,
    .mkdir = simplefs_mkdir,
};

static int simplefs_fill_super(struct super_block *sb, void *data, int silent)
{
    struct inode *root;

    sb->s_magic = SIMPLEFS_MAGIC;
    sb->s_op = &simplefs_super_ops;

    root = simplefs_make_inode(sb, S_IFDIR | 0755);
    if (!root)
        return -ENOMEM;
    root->i_op = &simplefs_dir_inode_operations;
    root->i_fop = &simple_dir_operations;

    sb->s_root = d_make_root(root);
    if (!sb->s_root)
        return -ENOMEM;

    return 0;
}
static struct dentry *simplefs_mount(struct file_system_type *fs_type, int flags, const char *dev_name, void *data)
{
    struct dentry *entry = mount_nodev(fs_type, flags, data, simplefs_fill_super);

    if (IS_ERR(entry))
        printk(KERN_ERR "simplefs: mounting failed\n");
    else
        printk(KERN_INFO "simplefs: mounted\n");

    return entry;
}
static struct file_system_type simplefs_type = {
    .owner = THIS_MODULE,
    .name = "simplefs",
    .mount = simplefs_mount,
    .kill_sb = kill_litter_super,
};
static int __init simplefs_init(void)
{
    int ret = register_filesystem(&simplefs_type);
    if (ret != 0) {
        printk(KERN_ERR "simplefs: cannot register filesystem\n");
        return ret;
    }
    printk(KERN_INFO "simplefs: module loaded\n");
    return 0;
}

static void __exit simplefs_exit(void)
{
    int ret = unregister_filesystem(&simplefs_type);

    if (ret != 0) {
        printk(KERN_ERR "simplefs: cannot unregister filesystem\n");
    }
    printk(KERN_INFO "simplefs: module unloaded\n");
}

module_init(simplefs_init);
module_exit(simplefs_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YEPURI SIDDU");
MODULE_DESCRIPTION("Filesystem");
MODULE_VERSION("0.1"); 

