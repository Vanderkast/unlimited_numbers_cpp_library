// cpp_unlimited_numbers_library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Реализовать в виде модуля набор подпрограмм для выполнения следующих операций над числами:
// арифметические операции, операции сравнения.

#include <iostream>
#include "test.h"
#include <vector>

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

int main() {
	setUp();

	testDigitCreationFromInt(6, { 0,1,1 });
	testDigitToInt(Digit(9), 9);
	testDigitCreationFromChar('5',  {1,0,1});
	testDigitToChar(Digit('7'), '7');
	Digit seven = Digit(7);
	Digit two = Digit('2');
	Digit* arr = new Digit[2];
	arr[0] = seven;
	arr[1] = two;
	testDigitSum(arr, 9);
	testDigitDifference(arr, 5);
	
	testDigitSumOverflow(arr, 0);
	testDigitDifferenceOverflow(arr, 0);
	arr[1] = Digit(9);
	testDigitSumOverflow(arr, 1);
	testDigitDifferenceOverflow(arr, 1);

	delete[] arr;
}

void setUp() {
	setlocale(LC_ALL, "Russian");
}

void testDigitCreationFromInt(int digit, std::vector<bool> validator){
	DigitCreationFromIntTest test = DigitCreationFromIntTest();
	test.run(digit, validator);
	cout << "Creation digit from int " << digit << " was " << test.message() << endl;
}

void testDigitToInt(Digit digit, int validator){
	DigitToIntTest test = DigitToIntTest();
	test.run(digit, validator);
	cout << "Converting Digit to int " << validator << " was " << test.message() << endl;
}

void testDigitCreationFromChar(char digit, std::vector<bool> validator) {
	DigitCreationFromCharTest test = DigitCreationFromCharTest();
	test.run(digit, validator);
	cout << "Creation digit from char " << digit << " was " << test.message() << endl;
}

void testDigitToChar(Digit digit, char validator){
	DigitToCharTest test = DigitToCharTest();
	test.run(digit, validator);
	cout << "Converting Digit to char " << validator << " was " << test.message() << endl;
}

void testDigitSum(Digit* input, int validator){
	DigitSumTest test = DigitSumTest();
	test.run(input, validator);
	cout << "Sum " << input[0].asChar() << " + " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitSumOverflow(Digit* input, int validator){
	DigitSumOverflowTest test = DigitSumOverflowTest();
	test.run(input, validator);
	cout << "Sum overflow from " << input[0].asChar() << " + " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitDifference(Digit* input, int validator){
	DigitDifferenceTest test = DigitDifferenceTest();
	test.run(input, validator);
	cout << "Difference " << input[0].asChar() << " - " << input[1].asChar() << " was " << test.message() << endl;
}

void testDigitDifferenceOverflow(Digit* input, int validator){
	DigitDifferenceOverflowTest test = DigitDifferenceOverflowTest();
	test.run(input, validator);
	cout << "Difference overflow from " << input[0].asChar() << " - " << input[1].asChar() << " was " << test.message() << endl;
}
