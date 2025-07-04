#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;

	std::cin >> N;

	std::vector<int> arr(N, 0);

	for (auto& num : arr)
		std::cin >> num;

	std::vector<int> dp{ arr };

	for (size_t i{ 1 }; i < arr.size(); ++i)
	{
		for (size_t j{ 0 }; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = std::max(dp[i], dp[j] + arr[i]);;
			}
		}
	}

	std::cout << *std::max_element(dp.begin(), dp.end());

	return 0;
}