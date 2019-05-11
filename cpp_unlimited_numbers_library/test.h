#pragma once

#include <string>
#include <vector>
#include "digit.h"

template <typename Input, typename Predictor>
struct Test {
public:
	virtual void run(Input, Predictor) = 0;
	virtual bool success() = 0;
	virtual std::string message() = 0;
};

template <typename Input, typename Predictor>
struct SimpleTest : Test<Input, Predictor> {
protected:
	std::string msg;
	bool scs;

	void setSuccessAndMessage(bool);
public:
	bool success();
	std::string message();
};

template<typename Input, typename Predictor>
inline void SimpleTest<Input, Predictor>::setSuccessAndMessage(bool result) {
	this->scs = result;
	this->msg = this->scs ? "successful" : "failure";
}

template<typename Input, typename Predictor>
inline bool SimpleTest<Input, Predictor>::success() {
	return this->scs;
}

template<typename Input, typename Predictor>
inline std::string SimpleTest<Input, Predictor>::message() {
	return this->msg;
}

class DigitCreationFromCharTest : public SimpleTest<char, std::vector<bool>> {
public:
	void run(char, std::vector<bool>);
};

class DigitCreationFromIntTest : public SimpleTest<int, std::vector<bool>> {
public:
	void run(int, std::vector<bool>);
};

class DigitToIntTest : public SimpleTest<Digit, int> {
public:
	void run(Digit, int);
};

class DigitToCharTest : public SimpleTest<Digit, char> {
public:
	void run(Digit, char);
};

class DigitSumTest : public SimpleTest<Digit[2], int> {
public:
	void run(Digit[2], int);
};

class DigitSumOverflowTest : public SimpleTest<Digit[2], int> {
public:
	void run(Digit[2], int);
};

class DigitDifferenceTest : public SimpleTest<Digit[2], int> {
public:
	void run(Digit[2], int);
};

class DigitDifferenceOverflowTest : public SimpleTest<Digit[2], int> {
public:
	void run(Digit[2], int);
};
