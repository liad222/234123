

#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>
#include <asm/uaccess.h>

#define NOPID  -10
#define ALREADYOFF -21
#define MALLOC -30
#define SIZETOOBIG -40
#define BADSIZEORPASS -50
#define BADPID -60

int sys_get_process_log(pid_t pid,int size,struct forbidden_activity_info* user_mem){
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

    if( pcb->log_index < size ){
        return SIZETOOBIG;
    }
    if(size < 0){
        return BADSIZEORPASS;
    }
    int i=0;

    copy_to_user(user_mem,pcb->our_log,sizeof(forbidden_activity_info)*size);

    int index = pcb->log_size - size;
    for(i=0; i< index; i++){
        pcb->our_log[i] = pcb->our_log[i+size];
    }
    int new_index = pcb->log_index - size;
    pcb->log_index = new_index;
    return 0;
}
