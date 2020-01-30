//
//

#include "DaemonHost.hpp"
#include <lib/threading/TaskScheduler.hpp>


DaemonHost::DaemonHost() {
    this->_scheduler = new TaskScheduler();
    this->_shouldContinue = true;
}

DaemonHost::~DaemonHost() {
    delete this->_scheduler;
}


void DaemonHost::start() {

    this->_shouldContinue = true;


    this->_scheduler->captureCurrentThread();

}

void DaemonHost::stop() {
    this->_scheduler->release();
}