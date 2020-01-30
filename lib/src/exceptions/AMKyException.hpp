//
//

#ifndef AMKY_DAEMON_AMKYEXCEPTION_HPP
#define AMKY_DAEMON_AMKYEXCEPTION_HPP


class AMKyException {

private:
    const String& _message;

public:

    AMKyException();

    AMKyException(const String& message);

    const String& getMessage();

};


#endif //AMKY_DAEMON_AMKYEXCEPTION_HPP
