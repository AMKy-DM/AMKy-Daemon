//
//

#ifndef AMKY_DAEMON__TYPE_DEFINITIONS_HPP
#define AMKY_DAEMON__TYPE_DEFINITIONS_HPP


struct RangeModel {
    unsigned long start;
    unsigned long end;
};

#define LOG_TAG "AMKy"

extern void log(const wchar_t* tag, const wchar_t* log);
extern void log(const char* tag, const char* log);

extern void log(const wchar_t* tag, const wchar_t* className, const wchar_t* functionName, const wchar_t* log);
extern void log(const char* tag, const char* className, const char* functionName, const char* log);


#endif //AMKY_DAEMON__TYPE_DEFINITIONS_HPP
