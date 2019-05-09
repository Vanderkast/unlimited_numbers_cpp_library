#include "test.h"
#include "digit.h" 

void DigitCreationFromCharTest::run(char input, std::vector<bool> validator) {
	Digit toTest = Digit(input);
	setSuccessAndMessage(toTest.vector() == validator);
}

void DigitToIntTest::run(Digit input, int validator) {
	int toTest = input.asInt();
	setSuccessAndMessage(toTest == validator);
}

void DigitCreationFromIntTest::run(int input, std::vector<bool> validator) {
	Digit toTest = Digit(input);
	setSuccessAndMessage(toTest.vector() == validator);
}

void DigitToCharTest::run(Digit input, char validator) {
	char toTest = input.asChar();
	setSuccessAndMessage(toTest == validator);
}

void DigitSumTest::run(Digit input[2], int validator) {
	Digit toTest = input[0];
	Digit ignored = toTest.plus(input[1]);
	setSuccessAndMessage(toTest.asInt() == validator);
}

void DigitSumOverflowTest::run(Digit input[2], int validator){
	Digit mirror = input[0];
	Digit toTest = mirror.plus(input[1]);
	setSuccessAndMessage(toTest.asInt() == validator);
}
