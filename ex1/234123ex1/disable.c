//
// Created by Liad on 13/11/2018.
//

#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define NOPID  -10
#define ALREADYOFF -21
#define MALLOC -30
#define BADSIZEORPASS -50
#define BADPID -60

int sys_disable_policy(pid_t pid, int password) {
    if(pid < 0){
        return BADPID;
    }
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if( pcb->our_policy == 0 ){
        return ALREADYOFF;
    }
    if(password != 234123){
        return BADSIZEORPASS;
    }
    pcb->our_policy = 0;
    pcb->log_size = 0;
    pcb->log_index = 0;
    pcb->our_privilege = 2;
    kfree(pcb->our_log);
    pcb->our_log = NULL;
    return 0;
}