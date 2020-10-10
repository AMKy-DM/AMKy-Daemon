//
//

#ifndef CPPLIB_THREAD_HPP
#define CPPLIB_THREAD_HPP

typedef unsigned long int pthread_t;

typedef void ThreadCallback();
typedef void ThreadCallbackWithState(void *state);

class Thread
{
private:
    pthread_t _ptr;
    ThreadCallback* _callback;
    ThreadCallbackWithState* _callbackWithState;

public:
    explicit Thread(ThreadCallback &callback);
    explicit Thread(ThreadCallbackWithState &callback, void *state);


    void join();

    void join(unsigned int milliseconds);


    static void yield();

    static void sleep(unsigned int milliseconds);


    void start();
};

#endif //CPPLIB_THREAD_HPP
