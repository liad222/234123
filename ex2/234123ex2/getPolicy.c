#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>

#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2
#define SCHED_CHANGEABLE 3
#define NOPID  -10
#define ARECHANGEABLE -20
#define BADVAL -30
#define NOCHANGEABLE -40

int sys_get_policy(pid_t pid) {
  task_t *pcb = find_task_by_pid(pid);
  if( pcb == NULL ){
      return NOPID;
  }
  if(pcb->policy != SCHED_CHANGEABLE){
    return NOCHANGEABLE;
  }
  return set_or_get_on(0);
}
