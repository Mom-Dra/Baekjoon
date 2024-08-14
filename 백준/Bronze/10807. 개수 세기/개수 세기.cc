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

	int v;
	int count{ 0 };
	
	std::cin >> v;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == v) ++count;
	}

	std::cout << count;
}