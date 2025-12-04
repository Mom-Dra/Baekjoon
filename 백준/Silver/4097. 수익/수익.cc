#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	while (true)
	{
		int N;
		std::cin >> N;

		if (N == 0) break;

		std::vector<int> nums(N);

		for (auto& num : nums)
			std::cin >> num;

		int max{ nums[0] };
		int totalMax{ nums[0] };

		for (size_t i{ 1 }; i < nums.size(); ++i)
		{
			max = std::max(nums[i], max + nums[i]);
			totalMax = std::max(totalMax, max);
		}

		std::cout << totalMax << '\n';
	}

	return 0;
}