#include <iostream>
#include <vector>

int main()
{
	constexpr int MOD{ 10007 };

	int n;
	std::cin >> n;

	std::vector<int> dp(n + 1, 0);

	dp[1] = 1;
	dp[2] = 3;

	for (int i{ 3 }; i <= n; ++i)
		dp[i] = (dp[i - 2] % MOD + dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;

	std::cout << dp[n];

	return 0;
}