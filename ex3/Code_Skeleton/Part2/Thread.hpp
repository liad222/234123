#ifndef __THREAD_H
#define __THREAD_H

#include "../Part1/PCQueue.hpp"
#include "../Part1/Semaphore.hpp"
#include "Job.hpp"
class Thread {
public:
    Thread(uint m_thread_id = 0) {
        // Only places thread_id
        this->m_thread_id = m_thread_id;
    }

    virtual ~Thread() {} // Does nothing

    /** Returns true if the thread was successfully started, false if there was an error starting the thread */
    bool start() {
        if (pthread_create(&m_thread, NULL, entry_func, this) == 0)
            return true;
        return false;
    }

    /** Will not return until the internal thread has exited. */
    void join() {
        pthread_join(m_thread, NULL);
    }

    /** Returns the thread_id **/
    uint thread_id() {
        return m_thread_id;
    }

protected:
    /** Implement this method in your subclass with the code you want your thread to run. */
    virtual void thread_workload() = 0;

    uint m_thread_id; // A number from 0 -> Number of threads initialized, providing a simple numbering for you to use

private:
    static void *entry_func(void *thread) {
        ((Thread *) thread)->thread_workload();
        return NULL;
    }

    pthread_t m_thread;
};


class game_Thread : public Thread {
private:
    bool_mat **curr;
    bool_mat **next;
    uint row;
    uint col;
    PCQueue<Job> *tasks;
    pthread_mutex_t *lock;
    pthread_mutex_t *Tlock;
    Job lines_Nums;
    vector<float> *m_tile_hist;

public:
    game_Thread(uint m_thread_id, bool_mat **curr, bool_mat **next,
                uint row, uint col, PCQueue<Job> *tasks,
                pthread_mutex_t *lock,pthread_mutex_t *Tlock,
                vector<float> *tile) :
            Thread(m_thread_id), curr(curr), next(next), row(row), col(col),
            tasks(tasks), lock(lock), Tlock(Tlock), m_tile_hist(tile) {}

    game_Thread() : Thread() {}

    ~game_Thread() override {}

    void thread_workload() override {
        while (1) {
            lines_Nums = tasks->pop();
            auto work_start = std::chrono::system_clock::now();
            if (lines_Nums.first == -1 && lines_Nums.last == -1) { ;
                return;
            }
            int counter = 0;
            for (int i = lines_Nums.first; i <= lines_Nums.last; ++i) { //row
                for (int j = 0; j < col; ++j) {                   //col
                    counter = 0;
                    for (int l = -1; l < 2; ++l) {//rows
                        for (int k = -1; k < 2; ++k) { //cols
                            if (l == 0 && k == 0) {
                                continue;
                            }
                            if (i + l < 0 || i + l >= row) {
                                continue;
                            }
                            if (j + k < 0 || j + k >= col) {
                                continue;
                            }
                            if ((**curr)[i + l][j + k] == true) {
                                counter++;
                            }
                        }

                    }
                    if (counter == 3) {
                        write_Next(i, j, true);
                        continue;
                    }
                    if (counter == 2 && (**curr)[i][j] == true) {
                        write_Next(i, j, true);
                        continue;
                    }
                    write_Next(i, j, false);
                }
            }
            auto work_end = std::chrono::system_clock::now();
            float time = (float) std::chrono::duration_cast<std::chrono::microseconds>(work_end - work_start).count();
            pthread_mutex_lock(Tlock);
            m_tile_hist->push_back(time);
            pthread_mutex_unlock(Tlock);
        }
    }

    void write_Next(int x, int y, bool val) {
        pthread_mutex_lock(lock);
        (**next)[x][y] = val;
        pthread_mutex_unlock(lock);
    }


};

#endif
