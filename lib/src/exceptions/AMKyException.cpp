//
//

#include "AMKyException.hpp"


AMKyException::AMKyException() {

}

AMKyException::AMKyException(const String &message) {
    this->_message = message;
}

String & AMKyException::getMessage() {
    return this->_message;
}