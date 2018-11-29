//
// Created by Liad on 22/11/2018.
//
#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2
#define SCHED_CHANGEABLE 3
#define NOPID  -10

int sys_is_changeable(pid_t pid) {
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if( pcb->policy == SCHED_CHANGEABLE ){
        printk("%d policy is - %d\n",pcb->policy ,set_or_get_on(0));
        return 1;
    }
    return 0;
}
