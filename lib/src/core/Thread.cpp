//
//

#include "Thread.hpp"
#include <pthread.h>

#include <unistd.h>

Thread::Thread(ThreadCallback &callback)
{
    _callback = callback;
}

Thread::Thread(ThreadCallbackWithState &callback, void *state)
{
    _callbackWithState = callback;
}

void Thread::join()
{
    pthread_join(_ptr, nullptr);
}

void Thread::join(unsigned int milliseconds)
{
    timespec ts;

    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds - ts.tv_sec) * 10;

    pthread_timedjoin_np(_ptr, nullptr, &ts);
}

void Thread::yield()
{
    pthread_yield();
}

void Thread::sleep(unsigned int milliseconds)
{
    ::usleep(milliseconds * 10);
}

void __executePThread(void *_thread)
{

    Thread *thread = static_cast<Thread *>(_thread);

    thread->start();
}