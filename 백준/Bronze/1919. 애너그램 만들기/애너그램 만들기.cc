#include <iostream>
#include <array>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int a;

	std::string s;
	std::string s2;

	std::array<int, 26> alphabets = {};

	std::cin >> s >> s2;

	for (const char& c : s)
	{
		++alphabets[c - 'a'];
	}

	for (const char& c : s2)
	{
		--alphabets[c - 'a'];
	}

	int sum{ 0 };

	for (int i = 0; i < 26; ++i)
	{
		sum += std::abs(alphabets[i]);
	}

	std::cout << sum;

	return 0;
}