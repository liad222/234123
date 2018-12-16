#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H
#include "Headers.hpp"
#include <pthread.h>
// Synchronization Warm up
class Semaphore {
public:
	Semaphore(): semCnt(0){
    queue<pthread_t> new_waiting;
    waiting=new_waiting;
		pthread_mutexattr_t attr;			//lock init
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
		pthread_mutex_t error_check_mutex;
		pthread_mutex_t error_check_mutex2;
		pthread_mutex_init(&error_check_mutex, &attr);
		pthread_mutex_init(&error_check_mutex2, &attr);
		cntLock = error_check_mutex;
		mainLock = error_check_mutex2;

  } // Constructs a new semaphore with a counter of 0

	Semaphore(unsigned val): semCnt(val){
    queue<pthread_t> new_waiting;
    waiting=new_waiting;
		pthread_mutexattr_t attr;		//lock init
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
		pthread_mutex_t error_check_mutex;
		pthread_mutex_t error_check_mutex2;
		pthread_mutex_init(&error_check_mutex, &attr);
		pthread_mutex_init(&error_check_mutex2, &attr);
		cntLock = error_check_mutex;
		mainLock = error_check_mutex2;
  }; // Constructs a new semaphore with a counter of val


	void up(){
		pthread_mutex_lock(&cntLock);
	  if (waiting.empty == true){
	    semCnt++;
			pthread_mutex_unlock(&cntLock);
	    return;
	  }
	  pthread_t curr = waiting.pop();//getting the thread from the queue;
	------
		pthread_mutex_unlock(&cntLock);
	} // Mark: 1 Thread has left the critical section
  // sem post

	void down(){
			pthread_mutex_lock(&cntLock);
	    if(semCnt>0){
	      semCnt--;
	    }
	    else{
	      waiting.push(pthread_self()); //adding the thread to our wait list
	      wait();
	    }
			pthread_mutex_unlock(&cntLock);

	} // Block untill counter >0, and mark - One thread has entered the critical section.
	//like sem_wait

private:
	unsigned int semCnt;
  queue<pthread_t> waiting;
	pthread_mutex_t cntLock;
	pthread_mutex_t mainLock;
};

#endif
