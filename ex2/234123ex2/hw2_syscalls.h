//
// Created by Liad on 22/11/2018.
//
#include <errno.h>
#include <sys/types.h>

#define NOPID  -10
#define ARECHANGEABLE -20
#define BADVAL -30
#define NOCHANGEABLE -40

int is_changeable(pid_t pid){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0"(243) , "b"(pid)
    :"memory"
    );

    if((res) == NOPID) {
        errno = ESRCH;
        return -1;
    }
    if((res) < 0) {
        errno = EINVAL;
        return -1;
    }
    return res;
}


int make_changeable(pid_t pid){
  int res;
  __asm__(
  "int $0x80;"
  : "=a" (res)
  : "0"(244) , "b"(pid)
  :"memory"
  );
  if((res) == NOPID) {
      errno = ESRCH;
      return -1;
  }
  if((res) == ARECHANGEABLE) {
      errno = EINVAL;
      return -1;
  }
  if((res) < 0) {
      errno = EINVAL;
      return -1;
  }
  return res;
}

int change(int val){
  int res;
  __asm__(
  "int $0x80;"
  : "=a" (res)
  : "0"(245) , "b"(val)
  :"memory"
  );
  if((res) == BADVAL) {
      errno = EINVAL;
      return -1;
  }
  if((res) < 0) {
      errno = EINVAL;
      return -1;
  }
  return res;
}

int get_policy(pid_t pid){
  int res;
  __asm__(
  "int $0x80;"
  : "=a" (res)
  : "0"(246) , "b"(pid)
  :"memory"
  );

  if((res) == NOPID) {
      errno = ESRCH;
      return  -1;
  }
  if((res) == NOCHANGEABLE) {
      errno = EINVAL;
      return  -1;
  }
  if((res) < 0) {
      errno = EINVAL;
      return  -1;
  }
  return res;
}
