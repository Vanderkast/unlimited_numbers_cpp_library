#pragma once

#include <vector>
#include <string>
#include "digit.h"

class Number {
protected:
	std::vector<Digit> digits = {};
	bool positive = true;

	void fillNumberFromString(Number& number, std::string& string);

public:
	Number();
	Number(Number*);
	Number(std::string number);

	bool equal(Number& number);
	/*bool operator>(Number& number);
	bool operator<(Number& number);
	bool operator>=(Number& number);
	bool operator<=(Number& number);*/

	/*Number operator+(Number&);
	Number operator-(Number&);
	Number operator*(Number&);
	Number operator/(Number&);
	Number operator%(Number&);*/

	int sign();

	void setPositive(bool);
	bool isPositive();

	std::string asString();

	std::vector<Digit> vector();
};
