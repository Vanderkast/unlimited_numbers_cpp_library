#include "unumber.h"
#include "unumber_exception.h"
#include "digit.h"

Number::Number() {
	this->positive = true;
	this->digits.push_back(Digit('0'));
}

Number::Number(Number* number) {
	this->positive = number->positive;
	this->digits = number->digits;
}

void checkOnLegal(std::string& number) {
	if (number.length() == 0)
		throw WrongNumberArgumentException("Length of number's string is 0.");
	if (number.find('.') == std::string::npos)
		throw WrongNumberArgumentException("'.' symbol found. Current library doesn't work with float numbers.");
}

void throwIncorrectDigitException(char& charDigit) {
	std::string error = "Incorrect symbol found: ";
	error.push_back(charDigit);
	throw WrongNumberArgumentException(error);
}

void checkCharDigitOnLegal(char& charDigit) {
	if ('0' > charDigit || charDigit > '9')
		throwIncorrectDigitException(charDigit);
}

void addDigitFromCharToVector(std::vector<Digit> & vector, char& charDigit) {
	checkCharDigitOnLegal(charDigit);
	vector.push_back(Digit(charDigit));
}

void Number::fillNumberFromString(Number & number, std::string & string) {
	number.setPositive(*(string.begin()) != '-');

	int scale = number.isPositive() ? 0 : 1;

	for (std::string::iterator numberIterator = string.end() - 1; numberIterator != string.begin() - scale; numberIterator--) {
		addDigitFromCharToVector(number.digits, *numberIterator);
	}
	addDigitFromCharToVector(number.digits, *(string.begin() - scale));
}

Number::Number(std::string number) {
	checkOnLegal(number);
	fillNumberFromString(*this, number);
}

bool boolEqual(bool& a, bool& b) {
	return a == b;
}

bool digitsEqual(std::vector<Digit> a, std::vector<Digit> b) {
	return a == b;
}

bool Number::equal(Number & number) {
	return boolEqual(this->positive, number.positive) && digitsEqual(this->digits, number.digits);
}

bool absolutelyBigger(std::vector<Digit> a, std::vector<Digit> b) {
	if (a.size() != b.size())
		return a.size() > b.size();

	unsigned int i = 0;
	for (; i < a.size(); i++) {
		if (a[i].asInt() != b[i].asInt())
			break;
	}
	return i == a.size() || a[i - 1].asInt() > b[i - 1].asInt();
}

//bool Number::operator>(Number & number) {
//	if (this->positive ^ number.positive)
//		return this->positive;
//	if (this->equal(number))
//		return false;
//	return this->positive == absolutelyBigger(this->digits, number.digits);
//}
//
//bool Number::operator<(Number & number) {
//	if (this->positive ^ number.positive)
//		return number.positive;
//	if (this->equal(number))
//		return false;
//	return this->positive == !absolutelyBigger(this->digits, number.digits);
//}
//
//bool Number::operator>=(Number & number) {
//	return !(*this < number);
//}
//
//bool Number::operator<=(Number & number) {
//	return !(*this > number);
//}

int Number::sign() {
	return this->positive ? 1 : -1;
}

void Number::setPositive(bool status) {
	this->positive = status;
}

bool Number::isPositive() {
	return this->positive;
}

std::string Number::asString() {
	std::string result = "";
	for (int i = this->digits.size() - 1; i >= 0; i--)
		result.push_back(this->digits[i].asChar());
	return result;
}

std::vector<Digit> Number::vector() {
	return this->digits;
}
