#include <iostream>
#include <vector>
#include <algorithm>

void BackTrack2(const std::vector<int>& arr, std::vector<int>& answer, int m, int last)
{
	if (answer.size() == m)
	{
		for (const auto& i : answer)
		{
			std::cout << i << ' ';
		}

		std::cout << '\n';
		return;
	}

	for (std::size_t i{ 0 }; i < arr.size(); ++i)
	{
		if (arr[i] >= last)
		{
			answer.emplace_back(arr[i]);

			BackTrack2(arr, answer, m, arr[i]);

			answer.pop_back();
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;

	std::cin >> n >> m;

	std::vector<int> arr(n);

	for (auto& num : arr)
	{
		std::cin >> num;
	}

	std::sort(arr.begin(), arr.end());
	arr.erase(std::unique(arr.begin(), arr.end()), arr.end());

	std::vector<int> answer;

	BackTrack2(arr, answer, m, 0);

	return 0;
}