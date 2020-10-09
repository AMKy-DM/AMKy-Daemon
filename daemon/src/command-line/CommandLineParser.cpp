//
//
#include <locale>
#include <codecvt>
#include <string>

#include "CommandLineParser.hpp"

using namespace std;

CommandLineParser::CommandLineParser(int argc, char **argv)
{

    // Arguments total count is known.
    _arguments.reserve(argc);

    // Using a converter to convert utf8 to utf16(wchar)
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    // Fill the _arguments.
    for (int i = 0; i < argc; i++)
    {
        wstring wide = converter.from_bytes(*argv);

        _arguments.push_back(wide);
    }

    if (argc > 0)
    {
        // The first argument is current directory in all OSs.
        _currentDirectory = _arguments[0];
    }

    if (argc > 1)
    {
        _command = _arguments[1];
        std::vector<decltype(_arguments)::value_type>(_arguments.begin() + 2,
                                                      _arguments.end())
            .swap(_arguments);

        _isCommandAvailable = true;
    }
    else if (argc > 0)
    {
        _arguments.erase(_arguments.begin());

        _isCommandAvailable = false;
    }

    _arguments.shrink_to_fit();
}

CommandLineParser::~CommandLineParser()
{
}

bool CommandLineParser::isCommandAvailable() const
{

    return _isCommandAvailable;
}

wstring CommandLineParser::getCommand() const
{

    if (_isCommandAvailable)
    {
        return _command;
    }

    return nullptr;
}

wstring CommandLineParser::getCurrentDirectory() const
{

    return _currentDirectory;
}

vector<wstring> CommandLineParser::getParameters() const
{

    return _arguments;
}

bool CommandLineParser::isCommand(const wchar_t* cmd) const {
    
    return _command.compare(cmd) == 0;
}