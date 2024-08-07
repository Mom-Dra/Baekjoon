#include <iostream>
#include <array>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::array<int, 12> dp;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;
		std::cout << dp[temp] << '\n';
	}
}