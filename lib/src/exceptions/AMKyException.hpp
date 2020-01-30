//
//

#ifndef AMKY_DAEMON_AMKYEXCEPTION_HPP
#define AMKY_DAEMON_AMKYEXCEPTION_HPP

class String;

class AMKyException {

private:
    const String& _message;

public:

    AMKyException();

    explicit AMKyException(const String& message);

    AMKyException(const String& className, const String& functionName, const String& message);

    const String& getMessage();

};


#endif //AMKY_DAEMON_AMKYEXCEPTION_HPP
