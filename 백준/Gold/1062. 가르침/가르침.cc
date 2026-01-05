#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>

void solve(const std::vector<std::bitset<26>>& arr, std::bitset<26>& bSet, int curr, int K, int& maxCount)
{
	if (bSet.count() == K)
	{
		int count{ 0 };

		for (const auto& set : arr)
		{
			if ((set & bSet) == set)
				++count;
		}

		maxCount = std::max(count, maxCount);

		return;
	}
	
	for (int i{ curr }; i < 26; ++i)
	{
		if (bSet.test(i)) continue;

		bSet.set(i);
		solve(arr, bSet, i + 1, K, maxCount);
		bSet.reset(i);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<std::bitset<26>> bSets(N);

	for (int i{0}; i < N; ++i)
	{
		std::string s;
		std::cin >> s;

		for (char c : s)
			bSets[i].set(c - 'a');
	}

	std::bitset<26> bSet;

	bSet.set('a' - 'a');
	bSet.set('n' - 'a');
	bSet.set('t' - 'a');
	bSet.set('i' - 'a');
	bSet.set('c' - 'a');

	int maxCount{ 0 };

	solve(bSets, bSet, 0, K, maxCount);

	std::cout << maxCount;

	return 0;
}