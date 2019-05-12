// cpp_unlimited_numbers_library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Реализовать в виде модуля набор подпрограмм для выполнения следующих операций над числами:
// арифметические операции, операции сравнения.

#include <iostream>
#include <vector>
#include "test.h"
#include "unumber.h"
#include "number_test.h"

using namespace std;

void setUp();
void testDigitCreationFromInt(int digit, std::vector<bool> validator);
void testDigitToInt(Digit digit, int validator);
void testDigitCreationFromChar(char digit, std::vector<bool> validator);
void testDigitToChar(Digit digit, char validator);
void testDigitSum(Digit* input, int validator);
void testDigitSumOverflow(Digit* input, int validator);
void testDigitDifference(Digit* input, int validator);
void testDigitDifferenceOverflow(Digit* input, int validator);

void testNumberCreationFromString(string input, string validator);

int main() {
	setUp();

	string number = "259";
	vector<Digit> validator = { Digit(2),Digit(5) ,Digit(6) };
	testNumberCreationFromString(number, number);
	Number a = Number("100");
	Number b = Number("100");
	bool result = a.equal(b);
	cout << (result ? 1 : -1) << endl;
}

void setUp() {
	setlocale(LC_ALL, "Russian");
}

void testDigitCreationFromInt(int digit, std::vector<bool> validator) {
	DigitCreationFromIntTest test = DigitCreationFromIntTest();
	test.run(digit, validator);
	cout << "Creation digit from int " << digit << " was " << test.message() << endl;
}

void testDigitToInt(Digit digit, int validator) {
	DigitToIntTest test = DigitToIntTest();
	test.run(digit, validator);
	cout << "Converting Digit to int " << validator << " was " << test.message() << endl;
}

void testDigitCreationFromChar(char digit, std::vector<bool> validator) {
	DigitCreationFromCharTest test = DigitCreationFromCharTest();
	test.run(digit, validator);
	cout << "Creation digit from char " << digit << " was " << test.message() << endl;
}

void testDigitToChar(Digit digit, char validator) {
	DigitToCharTest test = DigitToCharTest();
	test.run(digit, validator);
	cout << "Converting Digit to char " << validator << " was " << test.message() << endl;
}

void testDigitSum(Digit* input, int validator) {
	DigitSumTest test = DigitSumTest();
	test.run(input, validator);
	cout << "Sum " << input[0].asChar() << " + " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitSumOverflow(Digit* input, int validator) {
	DigitSumOverflowTest test = DigitSumOverflowTest();
	test.run(input, validator);
	cout << "Sum overflow from " << input[0].asChar() << " + " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitDifference(Digit* input, int validator) {
	DigitDifferenceTest test = DigitDifferenceTest();
	test.run(input, validator);
	cout << "Difference " << input[0].asChar() << " - " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitDifferenceOverflow(Digit* input, int validator) {
	DigitDifferenceOverflowTest test = DigitDifferenceOverflowTest();
	test.run(input, validator);
	cout << "Difference overflow from " << input[0].asChar() << " - " << input[1].asChar() << " was " << test.message() << endl;
}

void testNumberCreationFromString(string input, string validator){
	NumberCreationFromStringTest test = NumberCreationFromStringTest();
	test.run(input, validator);
	cout << "Creation number from string " << input << " was " << test.message() << endl;
}
