//
// Created by Liad on 22/11/2018.
//
#include <errno.h>
#include <sys/types.h>

#define NOPID  -10


int is_changable(pid_t pid){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0"(243) , "b"(pid)
    :"memory"
    );

    if((res) == NOPID) {
        errno = ESRCH;
        return 0;
    }
    if((res) < 0) {
        errno = EINVAL;
        return 0;
    }
    return res;
}


int enable_policy(pid_t pid){

}
/*
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
 */