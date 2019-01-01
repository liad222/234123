#ifndef _QUEUEL_H
#define _QUEUEL_H
#include "Headers.hpp"
// Single Producer - Multiple Consumer queue
template <typename T>class PCQueue
{
public:
	PCQueue(){
		producerInside = 0;
		consumerInside = 0;
		producerWaiting = 0;
		pthread_cond_init(&producerCond,NULL);
		pthread_cond_init(&consumerCond,NULL);
		pthread_mutexattr_t attr;            //lock init
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
		pthread_mutex_t error_check_mutex;
		pthread_mutex_init(&error_check_mutex, &attr);
		GLock = error_check_mutex;
        items = queue<T>();
		size=0;				//TODO DEBUG

	}


	void consumerLock(){
		pthread_mutex_lock(&GLock);
		while(consumerInside > 0 || producerInside > 0 || producerWaiting > 0 || items.empty() )
				pthread_cond_wait(&consumerCond,&GLock);
		consumerInside++;
        pthread_mutex_unlock(&GLock);
	}

	void consumerUnlock(){
		pthread_mutex_lock(&GLock);
        consumerInside--;
		if(consumerInside == 0)
			pthread_cond_signal(&producerCond);/// should we also broadcast for consumer?
		pthread_mutex_unlock(&GLock);
    }

	void producerLock(){
		pthread_mutex_lock(&GLock);
		producerWaiting++;
		while(producerInside > 0 || consumerInside > 0)
			pthread_cond_wait(&producerCond,&GLock);
		producerWaiting--;
		producerInside++;
        pthread_mutex_unlock(&GLock);
	}

	void producerUnlock(){
		pthread_mutex_lock(&GLock);
        producerInside--;
		if(producerInside == 0) {
			pthread_cond_broadcast(&consumerCond);
			pthread_cond_signal(&producerCond);
		}
		pthread_mutex_unlock(&GLock);
	}

	// Blocks while queue is empty. When queue holds items, allows for a single
	// thread to enter and remove an item from the front of the queue and return it.
	// Assumes multiple consumers.
	T pop(){
		consumerLock();
		T temp = items.front();
		items.pop();
		size--;
		consumerUnlock();
		return temp;
	}

	// Allows for producer to enter with *minimal delay* and push items to back of the queue.
	// Hint for *minimal delay* - Allow the consumers to delay the producer as little as possible.
	// Assumes single producer
	void push(const T& item){
		producerLock();
		size++;
		items.push(item);
		producerUnlock();
	}

    void pushmany(T* itemarr){
        producerLock();
        int i=0;
        while(itemarr[i] != nullptr) {
            items.push(itemarr[i]);
            size++;
            i++;
        }
        producerUnlock();
    }

	//returns the size of
	int getQueueSize(){
		int x=items.size();
		return x;
	}


private:
	int producerInside,consumerInside,producerWaiting;
	pthread_mutex_t GLock;
	pthread_cond_t producerCond;
	pthread_cond_t consumerCond;
	queue<T> items;
	int size;			//TODO DEBUG
};

// Recommendation: Use the implementation of the std::queue for this exercise
#endif
