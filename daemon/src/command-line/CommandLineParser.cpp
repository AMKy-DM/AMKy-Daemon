//
//

#include "CommandLineParser.hpp"
#include <TaskScheduler.hpp>

using namespace CppLib;


CommandLineParser::CommandLineParser(int argc, char **argv) {

}


int CommandLineParser::execute() {

    TaskScheduler taskScheduler;

    return taskScheduler.captureCurrentThread();

}