#ifndef AMKY_DAEMON_COMMANDDISPATCHER_HPP
#define AMKY_DAEMON_COMMANDDISPATCHER_HPP


class CommandLineParser;


class CommandDispatcher
{
private:
public:
    CommandDispatcher();

    int dispatch(const CommandLineParser& commandLineParser) const;
};

#endif //AMKY_DAEMON_COMMANDDISPATCHER_HPP