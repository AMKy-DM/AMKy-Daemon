//
//

#include "String.hpp"
#include <string>
#include <cstring>


String::String() {
    this->_buffer = new std::wstring(L"");
}

String::String(const String &str) {
    this->_buffer = new std::wstring(*str._buffer);
}

String::String(const wchar_t *str) {
    this->_buffer = new std::wstring(str);
}

String::String(const char *str) {
    const int size = strlen(str);

    this->_buffer = new std::wstring();
}

String::String(const unsigned int size, const char *str) {
    this->_buffer = new std::wstring();
}

String::String(const unsigned int size, const wchar_t *str) {
    this->_buffer = new std::wstring(str, size);
}

String::~String() {
    delete this->_buffer;
}

String& String::operator=(const String &str) {
    String result(str);
    return result;
}

unsigned int String::size() {
    return this->_buffer->size();
}
