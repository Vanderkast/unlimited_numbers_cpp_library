#include "unumber_exception.h"

NumberExceptionType WrongNumberArgumentException::type(){
	return INCORRECT_INPUT;
}

std::string WrongNumberArgumentException::caption(){
	return this->cptn;
}
