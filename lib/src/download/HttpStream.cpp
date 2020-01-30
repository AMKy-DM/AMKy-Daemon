//
//

#include "HttpStream.hpp"
#include <type-definitions.hpp>


HttpStream::HttpStream() {

}

bool HttpStream::readNextBlock(HttpStreamBlockCallback* callback, unsigned long bytes, long timeout) {
    if (callback == nullptr) {
        log(LOG_TAG, "HttpStream", "readNextBlock", "callback was null");

        throw new AMKyException("HttpStream", "readNextBlock", "callback was null");
    }

    if (timeout < -1) {
        log(LOG_TAG, "HttpStream", "readNextBlock", "timeout was less than -1");

        throw new AMKyException("HttpStream", "readNextBlock", "timeout was less than -1");
    }


}