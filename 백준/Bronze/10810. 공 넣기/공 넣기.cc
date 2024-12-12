#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> arr(N, 0);

	for (int i{ 0 }; i < M; ++i)
	{
		int start, end, num;
		std::cin >> start >> end >> num;

		std::fill(arr.begin() + (start - 1), arr.begin() + end, num);
	}

	for (const auto& num : arr)
		std::cout << num << ' ';

	return 0;
}