#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;

	std::cin >> n;

	std::vector<int> arr;
	arr.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;

		arr.push_back(temp);
	}

	int target;
	
	std::cin >> target;

	std::sort(arr.begin(), arr.end());

	auto low = std::lower_bound(arr.begin(), arr.end(), target);
	auto high = std::upper_bound(arr.begin(), arr.end(), target);

	if (low == arr.end()) std::cout << 0;
	else std::cout << std::distance(low, high);
}