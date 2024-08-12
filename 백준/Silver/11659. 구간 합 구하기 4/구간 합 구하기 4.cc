#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
	int n, m;

	std::cin >> n >> m;

	std::vector<int> arr;
	arr.reserve(n);

	arr.push_back(0);

	for (int i = 1; i <= n; ++i)
	{
		int temp;
		std::cin >> temp;
		arr.push_back(temp + arr[i - 1]);
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;

		std::cout << arr[b] - arr[a - 1] << '\n';
	}
}