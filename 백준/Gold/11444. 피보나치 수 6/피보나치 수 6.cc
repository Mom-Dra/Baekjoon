#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

constexpr int MOD{ 1000000007 };

std::uint64_t Fibo(std::uint64_t n, std::unordered_map<std::uint64_t, std::uint64_t>& dp)
{
	if (dp.find(n) != dp.end()) return dp[n];
		
	std::uint64_t temp;

	if (n % 2 == 0) temp = (Fibo(n / 2, dp) * (Fibo(n / 2 + 1, dp) + Fibo(n / 2 - 1, dp))) % MOD;
	else temp = ((Fibo((n + 1) / 2, dp) * Fibo((n + 1) / 2, dp)) % MOD) + ((Fibo((n - 1) / 2, dp) * Fibo((n - 1) / 2, dp)) % MOD) % MOD;

	dp[n] = temp % MOD;

	return dp[n];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::uint64_t num;
	std::cin >> num;

	std::unordered_map<std::uint64_t, std::uint64_t> dp;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	std::cout << Fibo(num, dp);
	return 0;
}