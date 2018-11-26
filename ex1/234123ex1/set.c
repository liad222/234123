//
// Created by Liad on 13/11/2018.
//

#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define NOPID  -10
#define ALREADYON -20
#define ALREADYOFF -21
#define MALLOC -30
#define BADSIZEORPASS -50
#define BADPID -60

int sys_set_process_capabilities(pid_t pid, int new_level,int password) {
    if(pid < 0){
        return BADPID;
    }
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if(password != 234123 || new_level < 0 || new_level > 2){
        return BADSIZEORPASS;
    }
    if( pcb->our_policy == 0 ){
        return ALREADYOFF;
    }

    pcb->our_privilege = new_level;
    return 0;
}