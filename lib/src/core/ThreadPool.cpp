//
//

#include "ThreadPool.hpp"
#include "Thread.hpp"
#include "ThreadPoolJobInfo.hpp"
#include "Monitor.hpp"


ThreadPool::ThreadPool()
{

    _continue = true;

    _jobQueueLock = std::make_unique<Mutex>();

    _minWorkerThreads = 0;
    _maxWorkerThreads = 100;
}

ThreadPool::~ThreadPool()
{

    this->stop();

    for (int i = 0; i < _jobs->count(); i++)
    {

        ThreadPoolJobInfo *job = _jobs->at(i);

        delete job;
    }

    for (int i = 0; i < _workerThreads->count(); i++)
    {

        Thread *thread = _workerThreads->get(i);

        delete thread;
    }
}

void ThreadPool::queueWorkItem(ThreadPoolCallback *callback)
{

    auto job = new ThreadPoolJobInfo(callback);

    _jobQueueLock->waitOne();

    _jobQueue->append(job);

    _jobQueueLock->release();

    Monitor::pulseOne(*this->_conditionalLock);
}

void ThreadPool::queueWorkItem(ThreadPoolCallbackWithState *callback, void *state)
{

    auto job = new ThreadPoolJobInfo(callback, state);

    _jobQueueLock->waitOne();

    _jobQueue->append(job);

    _jobQueueLock->release();

    Monitor::pulseOne(*this->_conditionalLock);
}

void ThreadPool::setWorkerThreads(int minWorkerThreads, int maxWorkerThreads)
{

    auto threads = _threadsCount;

    auto threadsToBeCreated = 0;

    if (threads < minWorkerThreads)
    {

        threadsToBeCreated = minWorkerThreads - threads;
    }

    if (threadsToBeCreated > 0)
    {
        for (int i = 0; i < threadsToBeCreated; i++)
        {
            Thread *thread = this->spawnThread();

            _workerThreadsLock->waitOne();

            _workerThreads->append(thread);

            _threadsCount++;

            _workerThreadsLock->release();
        }
    }

    this->_minWorkerThreads = minWorkerThreads;
    this->_maxWorkerThreads = maxWorkerThreads;
}

Thread *ThreadPool::spawnThread()
{

    auto thread = new Thread(_executeThread, this);

    return thread;
}

void ThreadPool::stop()
{

    //TODO: synchronization required.
    _continue = false;

    Monitor::pulseAll(*this->_conditionalLock);

    for (int i = 0; i < _workerThreads->count(); i++)
    {

        Thread *thread = _workerThreads->get(i);

        thread->join();
    }
}






void _executeThread(void *stt)
{

    auto that = static_cast<ThreadPool *>(stt);

    while (that->_continue)
    {

        ThreadPoolJobInfo *jobInfo = nullptr;

        that->_jobQueueLock->waitOne();

        if (that->_jobQueue->count() > 0)
        {

            jobInfo = that->_jobQueue->pop();
        }

        that->_jobQueueLock->release();

        if (jobInfo != nullptr)
        {

            jobInfo->execute();
        }

        if (!that->_continue)
        {

            return;
        }

        Monitor::wait(*that->_conditionalLock);
    }
}