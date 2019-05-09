#pragma once

#include <vector>

class Digit {
private:
	std::vector<bool> binary;

public:
	Digit();
	Digit(int);
	Digit(char);
	Digit(std::vector<bool>);
	Digit(Digit*);

	Digit plus(Digit&);
	Digit minus(Digit&);

	int asInt();
	char asChar();

	std::vector<bool> vector();
};
