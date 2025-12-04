#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
	int N;
	std::cin >> N;

	std::vector<double> nums(N);

	for (auto& num : nums)
		std::cin >> num;

	double max{ nums[0] };
	double totalMax{ nums[0] };

	for (size_t i{ 1 }; i < nums.size(); ++i)
	{
		max = std::max(nums[i], max * nums[i]);
		totalMax = std::max(totalMax, max);
	}

	std::cout << std::fixed;
	std::cout.precision(3);

	std::cout << totalMax;

	return 0;
}