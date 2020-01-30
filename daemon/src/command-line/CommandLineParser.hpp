//
//

#ifndef AMKY_DAEMON_COMMANDLINEPARSER_H
#define AMKY_DAEMON_COMMANDLINEPARSER_H


#include <String.hpp>
#include <string>

class CommandLineParser {
private:
    std::string _commands{};

public:
    CommandLineParser(int argc, char **argv);

    ~CommandLineParser() = default;

    int execute();

};


#endif //AMKY_DAEMON_COMMANDLINEPARSER_H
