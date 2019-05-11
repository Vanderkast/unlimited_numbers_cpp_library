#include "digit.h"

Digit::Digit() {
	this->binary.resize(1, false);
}

void absAndTrim(int& number) {
	number = abs(number) % 10;
}

void fillBinary(std::vector<bool>& vector, int number) {
	while (number > 1) {
		vector.push_back((bool)(number % 2));
		number /= 2;
	}
	vector.push_back((bool)number);
}

Digit::Digit(int number) {
	absAndTrim(number);
	fillBinary(this->binary, number);
}

int intFromChar(char& number) {
	return number - '0';
}

Digit::Digit(char charDigit){
	fillBinary(this->binary, intFromChar(charDigit));
}

Digit::Digit(std::vector<bool> vector){
	this->binary = vector;
}

Digit::Digit(Digit* number) {
	for (std::vector<bool>::iterator iterator = number->binary.begin(); iterator != number->binary.end(); iterator++) {
		this->binary.push_back(*iterator);
	}
}

Digit fillBinaryAndReturnOverflow(std::vector<bool>& binary, int number) {
	fillBinary(binary, number % 10);
	return Digit(number / 10);
}

Digit Digit::plus(Digit& number) {
	int sum = this->asInt() + number.asInt();
	this->binary.clear();
	return fillBinaryAndReturnOverflow(this->binary, sum);
}

void prepareDifferenceResult(int & number) {
	number = number > 0 ? number : (-1) * number + 10;
}

Digit Digit::minus(Digit& number) {
	int difference = this->asInt() - number.asInt();
	prepareDifferenceResult(difference);
	this->binary.clear();
	return fillBinaryAndReturnOverflow(this->binary, difference);
}

int Digit::asInt() {
	int i = 1, result = 0;
	for (std::vector<bool>::iterator iterator = this->binary.begin(); iterator != this->binary.end(); iterator++) {
		if (*iterator)
			result += i;
		i <<= 1;
	}
	return result;
}

char Digit::asChar() {
	return (char)(asInt() + (int)'0');
}

std::vector<bool> Digit::vector(){
	return this->binary;
}
