#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zhang Sidan");
MODULE_DESCRIPTION("OS homework 3.");
MODULE_VERSION("1.0");
static int hello_init(void) {

    struct task_struct *task;

    printk(KERN_INFO "Start listing tasks\n");
    for_each_process(task) {
        switch (task->state) {
        case TASK_RUNNING: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_RUNNING"); break;
        case TASK_INTERRUPTIBLE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_INTERRUPTIBLE"); break;
        case TASK_UNINTERRUPTIBLE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_UNINTERRUPTIBLE"); break;
        case __TASK_STOPPED: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "__TASK_STOPPED"); break;
        case __TASK_TRACED: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "__TASK_TRACED"); break;
        case EXIT_DEAD: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "EXIT_DEAD"); break;
        case EXIT_ZOMBIE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "EXIT_ZOMBIE"); break;
        case EXIT_TRACE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "EXIT_TRACE"); break;
        case TASK_PARKED: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_PARKED"); break;
        case TASK_DEAD: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_DEAD"); break;
        case TASK_WAKEKILL: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_WAKEKILL"); break;
        case TASK_WAKING: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_WAKING"); break;
        case TASK_NOLOAD: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_NOLOAD"); break;
        case TASK_NEW: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_NEW"); break;
        case TASK_STATE_MAX: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_STATE_MAX"); break;
        case TASK_KILLABLE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_KILLABLE"); break;
        case TASK_STOPPED: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_STOPPED"); break;
        case TASK_TRACED: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_TRACED"); break;
        case TASK_IDLE: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_IDLE"); break;
        case TASK_NORMAL: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_NORMAL"); break;
        case TASK_ALL: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_ALL"); break;
        case TASK_REPORT: printk(KERN_INFO "Process ID: %d Name: %-20s State: %s\t\n", task->pid, task->comm, "TASK_REPORT"); break;
        default : printk(KERN_WARNING "error!, %ld\n", task->state);
        }
    }
    printk(KERN_WARNING "Module init: Hello !\n");
    return 0;
}

static void hello_exit(void) {
    printk(KERN_WARNING "Module exit: bye-bye\n");
}

module_init(hello_init);
module_exit(hello_exit);
