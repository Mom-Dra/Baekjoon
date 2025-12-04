#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;

	for (int t{ 0 }; t < T; ++t)
	{
		int N;
		std::cin >> N;

		std::vector<int> nums(N);

		for (auto& num : nums)
			std::cin >> num;

		int max{ nums[0] };
		int totalMax{ nums[0] };

		for (int i{ 1 }; i < nums.size(); ++i)
		{
			max = std::max(nums[i], max + nums[i]);
			totalMax = std::max(totalMax, max);
		}

		std::cout << totalMax << '\n';
	}

	return 0;
}