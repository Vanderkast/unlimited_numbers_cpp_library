#include "number_test.h"
#include "unumber.h"

std::string getStringFromDigitVector(std::vector<Digit> vector) {
	std::string result = "";
	for (std::vector<Digit>::iterator iterator = vector.end() - 1; iterator != vector.begin(); iterator--)
		result.push_back((*iterator).asChar());
	result.push_back((*vector.begin()).asChar());
	return result;
}

void NumberCreationFromStringTest::run(std::string input, std::string validator){
	Number toTest = Number(input);
	setSuccessAndMessage(getStringFromDigitVector(toTest.vector()) == validator);
}
