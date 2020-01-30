//
//

#ifndef AMKY_DAEMON_BUFFER_HPP
#define AMKY_DAEMON_BUFFER_HPP


/**
 * A utility class to hold a byte-array as buffer.
 */
class Buffer {

private:
    static Buffer& _emptyBuffer;

    unsigned long _size;
    void* _ptr;

    Buffer();

public:

    Buffer(const Buffer& copy);

    Buffer(unsigned long size);

    Buffer(void* ptr, unsigned long pos, unsigned long size);

    ~Buffer();


    /**
     * @return The size of the buffer in bytes.
     */
    unsigned long size();

    /**
     * @param ptr pointer to the target memory location.
     * @param start The start index which copy starts from.
     * @param size The size of the buffer which should be copied to the target memory, pass -1 to copy remaining bytes.
     */
    void copy(void* ptr, unsigned long start, long size);

    static Buffer& empty();
};


#endif //AMKY_DAEMON_BUFFER_HPP
