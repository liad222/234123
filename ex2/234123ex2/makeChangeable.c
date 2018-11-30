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
#define ARECHANGEABLE -20
#define REALTIMEPROC -50

int sys_make_changeable(pid_t pid) {
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if( current->policy == SCHED_CHANGEABLE || pcb->policy == SCHED_CHANGEABLE ){
        return ARECHANGEABLE;
    }
    if(pcb->policy == SCHED_RR){
      return REALTIMEPROC;
    }
    pcb->policy = SCHED_CHANGEABLE;
    set_or_get_cnt(1);
    list_add_tail(&pcb->run_list_sc,getSC_list());
    return 0;
}
