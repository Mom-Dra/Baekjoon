#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string s;

	std::cin >> s;

	for (const auto& c : s)
		std::cout << static_cast<char>((islower(c) ? toupper(c) : tolower(c)));

	return 0;
}
