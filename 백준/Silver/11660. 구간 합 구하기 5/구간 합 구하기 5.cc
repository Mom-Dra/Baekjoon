#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
	int n{ 0 };
	int m{ 0 };

	std::cin >> n >> m;

	std::vector<std::vector<int>> arr(n + 1, std::vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int temp{ 0 };
			std::cin >> temp;

			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + temp - arr[i - 1][j - 1];
		}
	}
	
	for (int i = 0; i < m; ++i)
	{
		int sum{ 0 };

		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		sum = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];

		std::cout << sum << '\n';
	}
}