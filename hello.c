#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Daniel Zielas");
MODULE_DESCRIPTION("Simple hello world");
MODULE_VERSION("0.1");

static char *name = "world";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

static int __init helloBBB_init(void){
  printk(KERN_INFO "BBB: Hello %s from BBB LKM!\n", name);
  return 0;
}

static void __exit helloBBB_exit(void){
  printk(KERN_INFO "BBB: Goodbye %s from the BBB LKM!\n", name);
}

module_init(helloBBB_init);
module_exit(helloBBB_exit);
