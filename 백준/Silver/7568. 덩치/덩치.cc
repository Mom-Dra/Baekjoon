#include <iostream>
#include <vector>

int getRank(const std::vector<std::pair<int, int>>& frames, int index)
{
	int rank{ 1 };
	const auto& [targetWeight, targetHeight] {frames[index]};

	for (const auto& [weight, height] : frames)
	{
		if (weight > targetWeight && height > targetHeight)
			++rank;
	}

	return rank;
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> frames(N);

	for (auto& [weight, height] : frames)
		std::cin >> weight >> height;

	for (int i{ 0 }; i < N; ++i)
		std::cout << getRank(frames, i) << ' ';

	return 0;
}