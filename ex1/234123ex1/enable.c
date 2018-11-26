//
// Created by Liad on 07/11/2018.
//

#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define NOPID  -10
#define ALREADYON -20
#define MALLOC  -30
#define BADSIZEORPASS -50
#define BADPID -60

int sys_enable_policy(pid_t pid, int size, int password) {
    if(pid < 0){
        return BADPID;
    }
    task_t *pcb = find_task_by_pid(pid);
    if( pcb == NULL ){
        return NOPID;
    }
    if(password != 234123 || size < 0){
        return BADSIZEORPASS;
    }
    if( pcb->our_policy == 1 ){
        return ALREADYON;
    }

   forbidden_activity_info* log = kmalloc(size * sizeof(*log),GFP_KERNEL);
    if( log == NULL ){
        return MALLOC;
    }

    pcb->our_policy = 1;
    pcb->our_privilege = 2;
    pcb->our_log = log;
    pcb->log_size = size;
    return 0;
}
