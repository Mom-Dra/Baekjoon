#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	constexpr int BITCOUNT{ 21 };

	int N, M;
	std::cin >> N >> M;

	std::vector<std::bitset<BITCOUNT>> sets(N + 1);

	for (int i{ 0 }; i < M; ++i)
	{
		int op, n, x;
		std::cin >> op;

		switch (op)
		{
		case 1:
			std::cin >> n >> x;
			sets[n].set(x);
			break;

		case 2:
			std::cin >> n >> x;
			sets[n].reset(x);
			break;

		case 3:
			std::cin >> n;

			sets[n] <<= 1;
			break;

		case 4:
			std::cin >> n;

			sets[n] >>= 1;
			sets[n].reset(0);
			break;
		}
	}

	std::unordered_set<std::bitset<BITCOUNT>> uSet;
	uSet.reserve(N);

	for (int i{ 1 }; i <= N; ++i)
	{
		if (uSet.find(sets[i]) == uSet.end())
			uSet.insert(sets[i]);
	}

	std::cout << uSet.size();

	return 0;
}