#include "CommandDispatcher.hpp"
#include "CommandLineParser.hpp"

#include <_Include.hpp>
#include <config.hpp>

#include <stdio.h>

#define SUCCESS 0
#define FAILURE_UNKNOWN 1
#define UNKNOWN_COMMAND 2


#define COMMAND_HELP(cmd, message) LINE(" " cmd "\t\t" message)


CommandDispatcher::CommandDispatcher() {

}


void showHelp();


int CommandDispatcher::dispatch(const CommandLineParser& parser) const {
    
    if(!parser.isCommandAvailable()) {

        showHelp();

        return SUCCESS;
    }

    if (parser.isCommand(L"daemon")) {

        return SUCCESS;
    }

    if (parser.isCommand(L"http")) {

        return SUCCESS;
    }

    if (parser.isCommand(L"dl")) {

        return SUCCESS;
    }

    return UNKNOWN_COMMAND;

}

void showHelp() {

    printf(
        LINE("AMKy download manager")
        LINE("Version: %s")
        LINE("")
        LINE(" To get help about each level of the commands, put --help in the end of the command.")
        LINE("")
        LINE("------------")
        LINE("")

        COMMAND_HELP("http", "Passes the request to http interface.")
        COMMAND_HELP("dl", "Work with download manager.")
        COMMAND_HELP("config", "Get or set a config.")
        COMMAND_HELP("db", "Commands to work with the database.")
        LINE("")
        COMMAND_HELP("import", "Imports a download list.")
        COMMAND_HELP("export", "Exports database.")

        LINE("")

        COMMAND_HELP("--daemon", "Returns immediately and executes the command in daemon.")
        COMMAND_HELP("--proxy", "Sets proxy settings.")
        COMMAND_HELP("--network", "Sets network settings.")

        LINE("")
        LINE("------------")
        LINE("")
        COMMAND_HELP("help", "Prints this message.")
        LINE("")
    , PROJECT_VERSION);

}