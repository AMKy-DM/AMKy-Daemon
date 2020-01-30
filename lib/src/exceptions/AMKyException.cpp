//
//

#include "AMKyException.hpp"

#include <lib/String.hpp>


AMKyException::AMKyException() : _message(*new String("")) {

}

AMKyException::AMKyException(const String &message) : _message(message) {

}

AMKyException::AMKyException(const String &className, const String &functionName, const String &message)
    : _message(className + functionName + message) {

}


String & AMKyException::getMessage() {
    return this->_message;
}