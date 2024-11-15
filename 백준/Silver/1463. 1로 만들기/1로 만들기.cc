#include <iostream>
#include <vector>
#include <limits>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;


	std::vector<int> dp(n + 1);

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);
	}

	std::cout << dp[n];
}