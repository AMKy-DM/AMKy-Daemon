#include "CommandDispatcher.hpp"
#include "CommandLineParser.hpp"

#include <_Include.hpp>

#include <stdio.h>

#define SUCCESS 0
#define FAILURE_UNKNOWN 1

#define COMMAND_HELP(cmd, message) LINE(" " cmd "\t\t" message)

CommandDispatcher::CommandDispatcher() {

}


void showHelp();


int CommandDispatcher::dispatch(const CommandLineParser& commandLineParser) const {
    
    if(!commandLineParser.isCommandAvailable()) {

        showHelp();

        return SUCCESS;
    }

    return FAILURE_UNKNOWN;

}

void showHelp() {

    printf(
        LINE("version %s")
        LINE("AMKy download manager")
        LINE("")
        LINE(" To get help about each level of the commands, put --help in the end of the command.")
        LINE("")
        LINE("")

        COMMAND_HELP("daemon", "Starts the daemon.")
        COMMAND_HELP("http", "Passes the request to http interface.")


        LINE("")
        COMMAND_HELP("help", "Prints this message.")
        LINE("")
    , "test");

}