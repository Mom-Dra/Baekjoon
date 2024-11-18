#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> arr(3);
	std::vector<int> maxCurr(3);
	std::vector<int> maxPrev(3);
	std::vector<int> minCurr(3);
	std::vector<int> minPrev(3);

	for (auto& num : arr)
	{
		std::cin >> num;
	}

	maxPrev = arr;
	minPrev = arr;

	for (int i{ 1 }; i < n; ++i)
	{
		for (auto& num : arr)
		{
			std::cin >> num;
		}

		maxCurr[0] = std::max(maxPrev[0], maxPrev[1]) + arr[0];
		maxCurr[1] = std::max({ maxPrev[0], maxPrev[1], maxPrev[2] }) + arr[1];
		maxCurr[2] = std::max(maxPrev[1], maxPrev[2]) + arr[2];

		minCurr[0] = std::min(minPrev[0], minPrev[1]) + arr[0];
		minCurr[1] = std::min({ minPrev[0], minPrev[1], minPrev[2] }) + arr[1];
		minCurr[2] = std::min(minPrev[1], minPrev[2]) + arr[2];

		maxPrev = maxCurr;
		minPrev = minCurr;
	}

	auto max{ std::max_element(maxPrev.begin(), maxPrev.end()) };
	auto min{ std::min_element(minPrev.begin(), minPrev.end()) };

	std::cout << *max << ' ' << *min;

	return 0;
}