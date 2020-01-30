//
//

#ifndef AMKY_DAEMON_STRING_HPP
#define AMKY_DAEMON_STRING_HPP

#include <string>


/**
 * Represents a string.
 */
class String {
private:
    std::wstring* _buffer;

public:
    String();

    String(const String &str);

    String(const char *str);

    String(const wchar_t *str);

    String(unsigned int size, const char *str);

    String(unsigned int size, const wchar_t *str);

    ~String();

    String& operator=(const String &str);


    /**
     * @return The size of the string.
     */
    unsigned int size();

};


#endif //AMKY_DAEMON_STRING_HPP
