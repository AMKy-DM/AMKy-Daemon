//
//

#ifndef AMKY_DAEMON_DAEMON_H
#define AMKY_DAEMON_DAEMON_H

#include "lib/type-definitions.hpp"

class DaemonHost {

private:
    bool _shouldContinue;

public:

    void start();

    void stop();

};


#endif //AMKY_DAEMON_DAEMON_H
