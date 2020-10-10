#ifndef CPPLIB_THREADPOOL_HPP
#define CPPLIB_THREADPOOL_HPP

#include <memory>
#include <vector>

struct ThreadPoolJobInfo;

class Thread;

class ThreadPool
{
private:
    std::vector<ThreadPoolJobInfo*> _jobQueue;
    std::unique_ptr<Mutex> _jobQueueLock;

    std::vector<Thread *> _workerThreads;
    std::unique_ptr<Mutex> _workerThreadsLock;
    std::atomic<int> _threadsCount;

    int _minWorkerThreads;
    int _maxWorkerThreads;

    std::atomic<bool> _continue;

    std::unique_ptr<Monitor::ConditionalLockTarget> _conditionalLock;

    Thread *spawnThread();

    //static void ExecuteThread(void *state);

public:
    ThreadPool();

    ~ThreadPool();

    /**
         * Sets the minimum and maximum parked threads in the thread pool.
         * @param minWorkerThreads minimum parked threads.
         * @param maxWorkerThreads maximum parked threads.
         */
    void setWorkerThreads(int minWorkerThreads, int maxWorkerThreads);

    void stop();

    void queueWorkItem(ThreadPoolCallback *callback);

    void queueWorkItem(ThreadPoolCallbackWithState *callback, void *state);
};

#endif //CPPLIB_THREADPOOL_HPP
