#ifndef __THREAD_H
#define __THREAD_H

#include "PCQueue.hpp"
#include "Semaphore.hpp"

class Thread {
public:
    Thread(uint m_thread_id = 0) {
        // Only places thread_id
        this->m_thread_id = m_thread_id;
    }

    virtual ~Thread() {} // Does nothing

    /** Returns true if the thread was successfully started, false if there was an error starting the thread */
    bool start() {
        pthread_t th;
        if (pthread_create(&th, NULL, entry_func, &th) == 0)
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

    int done;
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
    bool_mat *curr;
    bool_mat *next;
    uint row;
    uint col;
    PCQueue<int *> *tasks;
    PCQueue<int *> *tasks_completed;
    Semaphore *lock;
    int *lines_Nums;


public:
    game_Thread(uint m_thread_id, bool_mat *curr, bool_mat *next,
                uint row, uint col, PCQueue<int *> *tasks,PCQueue<int *> *tasks_completed, Semaphore *lock) :
            Thread(m_thread_id), curr(curr), next(next),
            row(row), col(col), tasks(tasks),tasks_completed(tasks_completed), lock(lock) {}

    game_Thread() : Thread() {}

    ~game_Thread() override {}

    void thread_workload() override {
        while (1) {
            lines_Nums = tasks->pop();
            if (lines_Nums[0] == -1 && lines_Nums[1] == -1)
                break;
            int counter = 0;
            for (int i = lines_Nums[0]; i <= lines_Nums[1]; ++i) { //row
                for (int j = 0; j < col; ++j) {                   //col
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
                            if ((*curr)[i + l][j + k] == true) {
                                counter++;
                            }
                        }

                    }
                    if (counter == 3) {
                        write_Next(i, j, true);
                        continue;
                    }
                    if (counter == 2 && (*curr)[i][j] == true) {
                        write_Next(i, j, true);
                        continue;
                    }
                    write_Next(i, j, false);
                }
            }
            tasks_completed->push(lines_Nums);
        }
    }

    void write_Next(int x, int y, bool val) {
        lock->down();
        (*next)[x][y] = val;
        lock->up();
    }


};

#endif