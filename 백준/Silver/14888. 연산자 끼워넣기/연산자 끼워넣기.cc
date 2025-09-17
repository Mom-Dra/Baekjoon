#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

void backTrack(const std::vector<int>& arr, std::array<int, 4>& opCount, int length, int result, int& min, int& max, const int& N)
{
	if (length == N)
	{
		min = std::min(min, result);
		max = std::max(max, result);
		return;
	}

	for (int i{ 0 }; i < 4; ++i)
	{
		if (opCount[i] > 0)
		{
			int nextResult = result;

			if (i == 0) nextResult += arr[length];
			else if (i == 1) nextResult -= arr[length];
			else if (i == 2) nextResult *= arr[length];
			else nextResult /= arr[length];

			--opCount[i];
			backTrack(arr, opCount, length + 1, nextResult, min, max, N);
			++opCount[i];
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> arr(N, 0);

	for (auto& num : arr)
		std::cin >> num;

	std::array<int, 4> opCount{};

	for (auto& num : opCount)
		std::cin >> num;

	int min{ std::numeric_limits<int>::max() }, max{ std::numeric_limits<int>::min() };
	backTrack(arr, opCount, 1, arr[0], min, max, N);

	std::cout << max << '\n' << min;

	return 0;
}