//
//

#ifndef AMKY_DAEMON__TYPE_DEFINITIONS_HPP
#define AMKY_DAEMON__TYPE_DEFINITIONS_HPP


struct RangeModel {
    unsigned long start;
    unsigned long end;
};

#define LOG_TAG AMKy

extern void log(wchar_t* tag, wchar_t* log);
extern void log(char* tag, char* log);

extern void log(wchar_t* tag, wchar_t* className, char* functionName, wchar_t* log);
extern void log(char* tag, char* className, char* functionName, char* log);


#endif //AMKY_DAEMON__TYPE_DEFINITIONS_HPP
