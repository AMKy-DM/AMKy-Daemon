//
//

#include "command-line/CommandLineParser.hpp"

int main(int argc, char **argv) {

    CommandLineParser clp(argc, argv);

    return clp.execute();
}