//
//

#include "command-line/CommandLineParser.hpp"
#include <lib/Buffer.hpp>

int main(int argc, char **argv) {
     Buffer& b = Buffer::empty();

    CommandLineParser clp(argc, argv);

    return clp.execute();

}