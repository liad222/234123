//
// Created by Liad on 22/11/2018.
//
#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>


#define NOPID  -10
#define ARECHANGEABLE -20
#define OTHERERR -50

int sys_make_changeable(pid_t pid) {
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if( current->policy == SCHED_CHANGEABLE || pcb->policy == SCHED_CHANGEABLE ){
        return ARECHANGEABLE;
    }
    if( pcb->policy != SCHED_OTHER || pcb->state == TASK_ZOMBIE ){
      return OTHERERR;
    }
    pcb->policy = SCHED_CHANGEABLE;
    if(pcb->state != TASK_INTERRUPTIBLE && pcb->state != TASK_UNINTERRUPTIBLE ){
    list_add_tail(&pcb->run_list_sc, getSC_list());
    __set_bit(0, getSC_bitmap());
    setSC_nr();
  }
    set_or_get_cnt(1);
    return 0;
}
