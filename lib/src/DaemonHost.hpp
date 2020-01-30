//
//

#ifndef AMKY_DAEMON_DAEMON_H
#define AMKY_DAEMON_DAEMON_H

#include "lib/type-definitions.hpp"

class TaskScheduler;

class DaemonHost {

private:
    TaskScheduler* _scheduler;
    bool _shouldContinue;

public:

    DaemonHost();

    ~DaemonHost();

    void start();

    void stop();

};


#endif //AMKY_DAEMON_DAEMON_H
