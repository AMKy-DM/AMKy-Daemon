//
//

#ifndef CPPLIB_TASKSCHEDULER_HPP
#define CPPLIB_TASKSCHEDULER_HPP

#include <memory>
#include <vector>

#include "AsyncTask.hpp"

class ThreadPool;

class TaskScheduler
{
private:
    /**
         * Determines if captureCurrentThread method should continue to block the calling thread.
         *
         * @remarks Because this field is has been double checked in captureCurrentThread method,
         *          it's been marked as volatile to force compiler to read the value from memory instead of caching it in a register.
         */
    volatile bool _continue;

    std::shared_ptr<ThreadPool> _threadPool;

    std::vector<AsyncTask> _taskQueue;
    std::unique_ptr<Mutex> _taskQueueLock;

public:
    explicit TaskScheduler(const std::shared_ptr<ThreadPool> &threadPool);

    ~TaskScheduler();

    /**
         * Captures the calling thread to execute pending async tasks in task queue on the calling thread. (mainly the main thread)
         */
    int captureCurrentThread();

    /**
         * Releases the captured thread.
         */
    void release();

    /**
         * Pops one task from the async task queue and executes it on the calling thread.
         * @return true if a task was executed, otherwise false.
         */
    bool pullAndExecute();

    /**
         * Determines whether there are any more async tasks to be executed or not.
         * @return
         */
    bool isEmpty();

    /**
         * Schedules a new AsyncTask for async execution in the current TaskScheduler.
         * @param fn
         * @param state
         */
    void schedule(const AsyncTask &asyncTask);
};

#endif //CPPLIB_TASKSCHEDULER_HPP
