//
//

#ifndef CPPLIB_ASYNCTASK_HPP
#define CPPLIB_ASYNCTASK_HPP


class AsyncTask
{

public:
    AsyncTask();

    ~AsyncTask();

    bool isFinished();

    bool isError();

    void* wait();

    void* result();
};


template <typename T>
class AsyncTask : private AsyncTask {

public:
    AsyncTask();

    ~AsyncTask();


    T wait();

    T result();
}

#endif //CPPLIB_ASYNCTASK_HPP
