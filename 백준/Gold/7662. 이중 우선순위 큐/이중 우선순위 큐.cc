#include <iostream>
#include <algorithm>
#include <set>

int main()
{
	int T;
	std::cin >> T;

	for (int i{ 0 }; i < T; ++i)
	{
		std::multiset<int> ms;
		int k;
		std::cin >> k;

		for (int j{ 0 }; j < k; ++j)
		{
			char op;
			int num;

			std::cin >> op >> num;

			if (op == 'I') ms.insert(num);
			else if (op == 'D')
			{
				if (ms.empty()) continue;

				if (num == 1) ms.erase(std::prev(ms.end()));
				else ms.erase(ms.begin());
			}
		}

		if (ms.empty()) std::cout << "EMPTY\n";
		else std::cout << *std::prev(ms.end()) << ' ' << *ms.begin() << '\n';
	}

	return 0;
}