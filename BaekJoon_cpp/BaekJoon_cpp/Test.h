#pragma once

#include "Solution.h"
#include <iostream>

class Test : public Solution
{
public:
	void Solve() override
	{
		std::cout << "HEllo Wolrd";
	}
};