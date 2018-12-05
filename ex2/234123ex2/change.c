#include <linux/kernel.h>
#include <linux/slab.h>
#include <../include/linux/sched.h>


#define NOPID  -10
#define ARECHANGEABLE -20
#define BADVAL -30
#define OTHERERR -50

int sys_change(int val) {
  if(val != 0 && val != 1){
    return BADVAL;
  }
  if(set_or_get_cnt(0) == 0){
    return 0;
  }
  if(val == 1){
    set_or_get_on(1);
    if(is_min(current) == 0){
      set_tsk_need_resched(current);
    }
    return 0;
  }
    set_or_get_on(-1);
    return 0;
}
