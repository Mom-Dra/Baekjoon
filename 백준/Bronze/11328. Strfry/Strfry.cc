#include <iostream>
#include <array>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;

	std::cin >> n;

	

	for (int i = 0; i < n; ++i)
	{
		std::string s;
		std::string s2;
		std::array<int, 26> alphabets = {};

		std::cin >> s >> s2;

		bool isPossible{ true };

		for (const char& c : s)
		{
			++alphabets[c - 'a'];
		}

		for (const char& c : s2)
		{
			--alphabets[c - 'a'];
		}

		for (int j = 0; j < 26; ++j)
		{
			if (alphabets[j] != 0)
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
			std::cout << "Possible\n";
		else
			std::cout << "Impossible\n";
	}
}