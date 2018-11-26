//
// Created by Liad on 22/11/2018.
//

#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2
#define SCHED_CHANGEABLE 3
#define NOPID  -10
#define ARECHANGEABLE -20
int sys_make_changeable(pid_t pid) {
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }

    if( current->policy == SCHED_CHANGEABLE || pcb->policy == SCHED_CHANGEABLE ){
        return ARECHANGEABLE;
    }

    pcb->policy == SCHED_CHANGEABLE;

    return 0;
}