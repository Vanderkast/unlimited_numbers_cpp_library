#pragma once

#include <string>
#include <vector>

#include "test.h"
#include "unumber.h"

class NumberCreationFromStringTest : public SimpleTest<std::string, std::string> {
public:
	void run(std::string, std::string);
};
