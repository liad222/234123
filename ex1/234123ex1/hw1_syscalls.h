//
// Created by Liad on 07/11/2018.
//

#include <errno.h>
#include <sys/types.h>


#define NOPID  -10
#define ALREADYON -20
#define ALREADYOFF -21
#define MALLOC -30
#define SIZETOOBIG -40
#define BADSIZEORPASS -50
#define BADPID -60

struct forbidden_activity_info{
    int syscall_req_level;
    int proc_level;
    int time;
};


int enable_policy(pid_t pid, int size, int password){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0"(243) , "b"(pid), "c"(size), "d"(password)
    :"memory"
    );
    if((res) == BADSIZEORPASS){
        errno = EINVAL;
        return -1;
    }
    if((res) == BADPID){
        errno = ESRCH;
        return -1;
    }
    if((res) == NOPID) {
        errno = ESRCH;
        return -1;
    }
    if((res) == ALREADYON) {
        errno = EINVAL;
        return -1;
    }

    if((res) == MALLOC) {
        errno = ENOMEM;
        return -1;
    }

    if((res) < 0) {
        errno = EINVAL;
        return -1;
    }
    return res;
}

int disable_policy(pid_t pid, int password){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0"(244) , "b"(pid), "c"(password)
    :"memory"
    );
    if((res) == BADSIZEORPASS){
        errno = EINVAL;
        return -1;
    }
    if((res) == BADPID){
        errno = ESRCH;
        return -1;
    }
    if((res) == NOPID) {
        errno = ESRCH;
        return -1;
    }

    if((res) == ALREADYOFF) {
        errno = EINVAL;
        return -1;
    }

    if((res) < 0) {
        errno = EINVAL;
        return -1;
    }
    return res;
}

int set_process_capabilities(pid_t pid, int new_level, int password){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0"(245) , "b"(pid), "c"(new_level), "d"(password)
    :"memory"
    );
    if((res) == BADPID){
        errno = ESRCH;
        return -1;
    }
    if((res) == BADSIZEORPASS){
        errno = EINVAL;
        return -1;
    }
    if((res) == NOPID) {
        errno = ESRCH;
        return -1;
    }

    if((res) == ALREADYOFF) {
        errno = EINVAL;
        return -1;
    }

    if((res) == MALLOC) {
        errno = ENOMEM;
        return -1;
    }
    if((res) < 0) {
        errno = EINVAL;
        return -1;
    }
    return res;
}

int get_process_log(pid_t pid,int size,struct forbidden_activity_info* user_mem) {
  int res;
  __asm__(
  "int $0x80;"
  : "=a" (res)
  : "0"(246) , "b"(pid), "c"(size), "d"(user_mem)
  :"memory"
  );
  if((res) == BADPID){
        errno = ESRCH;
        return -1;
    }
  if((res) == NOPID) {
      errno = ESRCH;
      return -1;
  }
  if((res) == BADSIZEORPASS){
        errno = EINVAL;
        return -1;
  }
  if((res) == SIZETOOBIG){
      errno = EINVAL;
      return -1;
  }

  if((res) == ALREADYOFF) {
      errno = EINVAL;
      return -1;
  }

  if((res) < 0) {
      errno = EINVAL;
      return -1;
  }
  return res;
}
