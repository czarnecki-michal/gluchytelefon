#include <linux/init.h>           // Macros used to mark up functions e.g. __init __exit
#include <linux/module.h>         // Core header for loading LKMs into the kernel
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/kernel.h>         // Contains types, macros, functions for the kernel
#include <linux/fs.h>             // Header for the Linux file system support
#include <linux/uaccess.h>          // Required for the copy to user function

#include "jajko.h"
 
MODULE_LICENSE("GPL");            ///< The license type -- this affects available functionality
MODULE_AUTHOR("MC");    ///< The author -- visible when you use modinfo
MODULE_DESCRIPTION("Linux Kernel Module over chrdev.");  ///< The description -- see modinfo
MODULE_VERSION("0.1");            ///< A version number to inform users
 
static int    majorNumber;                  ///< Stores the device number -- determined automatically
static char   message[BUFFER_SIZE] = {0};           ///< Memory for the string that is passed from userspace
static struct class*  jajkoClass  = NULL; ///< The device-driver class struct pointer
static struct device* jajkoDevice = NULL; ///< The device-driver device struct pointer

static struct file_operations fops =
{
   .read = dev_read,
   .write = dev_write,
};

static int __init jajko_init(void){
   printk(KERN_INFO "jajko: Initializing the jajko LKM\n");
 
   // Try to dynamically allocate a major number for the device -- more difficult but worth it
   majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
   if (majorNumber<0){
      printk(KERN_ALERT "jajko failed to register a major number\n");
      return majorNumber;
   }
   printk(KERN_INFO "jajko: registered correctly with major number %d\n", majorNumber);
 
   // Register the device class
   jajkoClass = class_create(THIS_MODULE, CLASS_NAME);
   if (IS_ERR(jajkoClass)){                // Check for error and clean up if there is
      unregister_chrdev(majorNumber, DEVICE_NAME);
      printk(KERN_ALERT "Failed to register device class\n");
      return PTR_ERR(jajkoClass);          // Correct way to return an error on a pointer
   }
   printk(KERN_INFO "jajko: device class registered correctly\n");
 
   // Register the device driver
   jajkoDevice = device_create(jajkoClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
   if (IS_ERR(jajkoDevice)){               // Clean up if there is an error
      class_destroy(jajkoClass);           // Repeated code but the alternative is goto statements
      unregister_chrdev(majorNumber, DEVICE_NAME);
      printk(KERN_ALERT "Failed to create the device\n");
      return PTR_ERR(jajkoDevice);
   }
   printk(KERN_INFO "jajko: device class created correctly\n"); // Made it! device was initialized
   return 0;
}

static void __exit jajko_exit(void){
   device_destroy(jajkoClass, MKDEV(majorNumber, 0));     // remove the device
   class_unregister(jajkoClass);                          // unregister the device class
   class_destroy(jajkoClass);                             // remove the device class
   unregister_chrdev(majorNumber, DEVICE_NAME);             // unregister the major number
   printk(KERN_INFO "jajko: Goodbye from the LKM!\n");
}
 
static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
   // copy_to_user has the format ( * to, *from, size) and returns 0 on success
   copy_to_user(buffer, message, BUFFER_SIZE);
   return len;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
    strcpy(message, buffer);
    return len;
}


module_init(jajko_init);
module_exit(jajko_exit);

