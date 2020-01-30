//
//

#ifndef AMKY_DAEMON_HTTPSTREAM_HPP
#define AMKY_DAEMON_HTTPSTREAM_HPP

class Buffer;

typedef void HttpStreamBlockCallback(const Buffer& buffer, unsigned long startIndex);

class HttpStream {

private:


public:
    HttpStream();

    bool readNextBlock(HttpStreamBlockCallback* callback, unsigned long bytes, long timeout = -1);

};


#endif //AMKY_DAEMON_HTTPSTREAM_HPP
