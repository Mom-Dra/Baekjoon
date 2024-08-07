#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::unordered_map<char, int> m;

	for (const char& c : s)
	{
		if (m.find(c) != m.end())
		{
			++m[c];
		}
		else
		{
			m.insert(std::make_pair(c, 1));
		}
	}

	for (char c = 'a'; c <= 'z'; ++c)
	{
		if (m.find(c) != m.end())
		{
			std::cout << m[c];
		}
		else
		{
			std::cout << 0;
		}
		std::cout << ' ';
	}
}