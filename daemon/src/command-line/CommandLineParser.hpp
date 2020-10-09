//
//

#ifndef AMKY_DAEMON_COMMAND_LINE_PARSER_H
#define AMKY_DAEMON_COMMAND_LINE_PARSER_H

#include <string>
#include <vector>
#include <array>

using namespace std;

class CommandLineParser {
private:
    wstring _currentDirectory;
    wstring _command;

    bool _isCommandAvailable;

    vector<wstring> _arguments;

public:
    CommandLineParser(int argc, char **argv);

    ~CommandLineParser();

    wstring getCurrentDirectory() const;

    bool isCommandAvailable() const;

    wstring getCommand() const;

    vector<wstring> getParameters() const;

};


#endif //AMKY_DAEMON_COMMAND_LINE_PARSER_H
