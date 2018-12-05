#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define NOPID  -10
#define ARECHANGEABLE -20
#define BADVAL -30
#define NOCHANGEABLE -40
#define OTHERERR -50

int sys_get_policy(pid_t pid) {
  task_t *pcb = find_task_by_pid(pid);
  if( pcb == NULL ){
      return NOPID;
  }
  if(pcb->state == TASK_ZOMBIE){
    return OTHERERR;
  }
  if(pcb->policy != SCHED_CHANGEABLE){
    return NOCHANGEABLE;
  }
  return set_or_get_on(0);
}
