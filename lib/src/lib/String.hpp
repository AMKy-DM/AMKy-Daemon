//
//

#ifndef AMKY_DAEMON_STRING_HPP
#define AMKY_DAEMON_STRING_HPP


class String {
private:
    int _size;
    wchar_t *_buffer;

public:
    String();

    String(const String &str);

    String(const char *str);

    String(const wchar_t *str);

    ~String();

    String operator=(const String &str);

};


#endif //AMKY_DAEMON_STRING_HPP
