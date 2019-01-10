#include <linux/module.h>
#include <linux/kernel.h>
#include <asm-i386/current.h>
#include <linux/syscall.h>
#include <linux/utsname.h>
#include <asm-i386/unistd.h>

// TODO: add more #include statements as necessary


MODULE_LICENSE("GPL");
MODULE_AUTHOR("YOUR NAMES");


// TODO: add command-line arguments
int scan_range = 135;
char *program_name;
MODULE_PARM(program_name,"s");
//MODULE_PARM(scan_range,"i");
void** sys_call_table = NULL;
// TODO: import original syscall and write new syscall
/*
int strcmp(char** str1,char** str2){
  int i =0;
  while(str1[i] != 0 && str2[i] != 0){
    if(str1[i] != str2[i]){
      return 0;
    }
    i++;
  }
  if(str1[i] != 0 || str2[i] != 0){
    return 0;
  }
  return 1;
}*/

asmlinkage long our_sys_kill(int pid, int sig){
  task_t *pcb = find_task_by_pid(pid);
  if(pcb != NULL && strcmp((pcb->comm),program_name) == 0 && sig == SIGKILL){
    return -EPERM;
  }
  else{
  return sys_kill(pid,sig);
      }
}

void find_sys_call_table(int scan_range) {
   // TODO: complete the function
   asmlinkage ssize_t (**orig_sys_read)(unsigned int, char*, size_t);
   void* start = &system_utsname;
   int i = 0;
   for (; i < scan_range; i++) {
     start += 4;
     orig_sys_read = start;
    if( *orig_sys_read == sys_read){
      sys_call_table = orig_sys_read - (__NR_read);
      return;
    }
   }
}

int init_module(void) {
   if(program_name == NULL){
     return 0;
   }
find_sys_call_table(scan_range);
sys_call_table[__NR_kill]=&our_sys_kill;
return 0;
}

void cleanup_module(void) {
      if(sys_call_table != NULL){
      sys_call_table[__NR_kill] = &sys_kill;
    }
  }
