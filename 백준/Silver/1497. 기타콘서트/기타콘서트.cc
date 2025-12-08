#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr int MAX_M{ 50 };

void backTrack(const std::vector<std::bitset<MAX_M>>& possibles, int index, int count, std::bitset<MAX_M> possible, int& maxSong, int& minCount, int N)
{
	if (index == N)
	{
		if (possible.count() > maxSong)
		{
			maxSong = possible.count();
			minCount = count;
		}
		else if (possible.count() == maxSong)
		{
			minCount = std::min(minCount, count);
		}

		return;
	}

	backTrack(possibles, index + 1, count + 1, possible | possibles[index], maxSong, minCount, N);
	backTrack(possibles, index + 1, count, possible, maxSong, minCount, N);
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::bitset<MAX_M>> possibles;
	possibles.reserve(M);

	for (int i{ 0 }; i < N; ++i)
	{
		std::string guitar;
		std::string possible;

		std::cin >> guitar >> possible;

		std::bitset<MAX_M> set;

		for (size_t j{ 0 }; j < possible.size(); ++j)
		{
			if (possible[j] == 'Y')
			{
				set.set(j);
			}
		}

		possibles.emplace_back(set);
	}

	int maxSong{ 0 };
	int minCount{ 0 };

	backTrack(possibles, 0, 0, std::bitset<MAX_M>{}, maxSong, minCount, N);

	std::cout << (maxSong == 0 ? -1 : minCount);

	return 0;
}