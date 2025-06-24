#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::array<int, 3>> cost(N);

	for (auto& arr : cost)
	{
		for (auto& num : arr)
		{
			std::cin >> num;
		}
	}

	std::vector<std::array<int, 3>> dp(N, std::array<int, 3>{0, 0, 0});

	for (int i{ 0 }; i < 3; ++i)
	{
		dp[0][i] = cost[0][i];
	}

	for (int i{ 1 }; i < N; ++i)
	{
		dp[i][0] = cost[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
	}

	std::cout << std::min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });

	return 0;
}