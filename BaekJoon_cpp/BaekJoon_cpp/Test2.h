#pragma once

#include "Solution.h"
#include <iostream>

class Test2 : public Solution
{
	void Solve() override
	{
		std::cout << "KiaOra\n";
		std::cout << "Hello World";
	}
};