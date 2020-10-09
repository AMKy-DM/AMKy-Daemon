#include "command-line/CommandLineParser.hpp"
#include "command-line/CommandDispatcher.hpp"

int main(int argc, char **argv)
{
    CommandLineParser const clp(argc, argv);

    CommandDispatcher const cd;
    
    return cd.dispatch(const_cast<CommandLineParser&> (clp));
}