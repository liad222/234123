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
        printk("change status is - %d, number of SC is - %d, no SC in list - %d\n",set_or_get_on(0),set_or_get_cnt(0),list_empty(getSC_list()));
        return NOPID;
    }
    if( pcb->policy == SCHED_CHANGEABLE ){
        printk("change status is - %d, number of SC is - %d, no SC in list - %d\n",set_or_get_on(0),set_or_get_cnt(0),list_empty(getSC_list()));
        return 1;
    }
    return 0;
}
