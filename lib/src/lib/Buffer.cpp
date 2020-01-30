//
//

#include "Buffer.hpp"


Buffer::Buffer() {
    this->size = 0;
    this->_ptr = nullptr;
}

Buffer::Buffer(const Buffer &copy) {

}

Buffer::Buffer(unsigned long size) {

}

Buffer::Buffer(void *ptr, unsigned long pos, unsigned long size) {

}

Buffer::~Buffer() {

}

unsigned long Buffer::size() {
    return this->_size;
}


Buffer& Buffer::empty() {
    return Buffer::_emptyBuffer;
}