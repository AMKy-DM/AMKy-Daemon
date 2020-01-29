//
//

#ifndef AMKY_DAEMON_COMMANDLINEPARSER_H
#define AMKY_DAEMON_COMMANDLINEPARSER_H


#include <String.hpp>

class CommandLineParser {
private:
    String _commands{};

public:
    CommandLineParser(int argc, char **argv);

    ~CommandLineParser();

    int execute();

};


#endif //AMKY_DAEMON_COMMANDLINEPARSER_H
