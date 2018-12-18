#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H

#include "Headers.hpp"
#include <pthread.h>

// Synchronization Warm up
class Semaphore {
public:
    Semaphore() : semCnt(0) {
        queue<pthread_t> new_waiting;
        waiting = new_waiting;
        pthread_mutexattr_t attr;            //lock init
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
        pthread_mutex_t error_check_mutex;
        pthread_mutex_init(&error_check_mutex, &attr);
        cntLock = error_check_mutex;
        pthread_cond_init(cond, NULL);
    } // Constructs a new semaphore with a counter of 0

    Semaphore(unsigned val) : semCnt(val) {
        queue<pthread_t> new_waiting;
        waiting = new_waiting;
        pthread_mutexattr_t attr;            //lock init
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
        pthread_mutex_t error_check_mutex;
        pthread_mutex_init(&error_check_mutex, &attr);
        cntLock = error_check_mutex;
        pthread_cond_init(cond, NULL);
    } // Constructs a new semaphore with a counter of val


    void up() {
        pthread_mutex_lock(&cntLock);
        semCnt++;
        pthread_cond_broadcast(cond);
        pthread_mutex_unlock(&cntLock);
    } // Mark: 1 Thread has left the critical section
    // sem post

    void down() {
        pthread_mutex_lock(&cntLock);
        waiting.push(getpid());
        while (semCnt == 0 || getpid() != waiting.front()) {
            pthread_cond_wait(cond, &cntLock);
        }
        waiting.pop();
        semCnt--;
        pthread_mutex_unlock(&cntLock);
    } // Block untill counter >0, and mark - One thread has entered the critical section.
    //like sem_wait

private:
    unsigned int semCnt;
    queue<pthread_t> waiting;
    pthread_mutex_t cntLock;
    pthread_cond_t *cond;
};

#endif
