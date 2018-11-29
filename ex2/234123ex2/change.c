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

int sys_change(int val) {
  if(val != 0 && val != 1){
    return BADVAL;
  }
  if(set_or_get_cnt(0) == 0){
    printk("change status is - %d, number of SC is - %d, no SC in list - %d\n",set_or_get_on(0),set_or_get_cnt(0),list_empty(getSC_list()));
    return 0;
  }
  if(val == 1){
    set_or_get_on(1);
    printk("change status is - %d, number of SC is - %d, no SC in list - %d\n",set_or_get_on(0),set_or_get_cnt(0),list_empty(getSC_list()));
    return 0;
  }
    set_or_get_on(-1);
    printk("change status is - %d, number of SC is - %d, no SC in list - %d\n",set_or_get_on(0),set_or_get_cnt(0),list_empty(getSC_list()));
    return 0;
}
