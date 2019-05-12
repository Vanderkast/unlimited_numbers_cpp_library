#pragma once

#include <exception>
#include <string>

enum NumberExceptionType {
	INCORRECT_INPUT,
};

struct NumberException : public std::exception{
public:
	virtual NumberExceptionType type() = 0;
	
	virtual std::string caption() = 0;
};

class WrongNumberArgumentException : public NumberException {
private:
	std::string cptn;

public:
	WrongNumberArgumentException(std::string caption) {
		this->cptn = caption;
	}

	NumberExceptionType type();

	std::string caption();
};
