//
// Created by Liad on 22/11/2018.
//
#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>


#define NOPID  -10
#define OTHERERR -50

int sys_is_changeable(pid_t pid) {
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if(pcb->state == TASK_ZOMBIE){
      return OTHERERR;
    }
    if( pcb->policy == SCHED_CHANGEABLE ){
        return 1;
    }
    return 0;
}
