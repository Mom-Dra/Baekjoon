#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> arr(N, 0);

	for (auto& num : arr)
		std::cin >> num;

	std::vector<int> dp(N + 1, 0);

	dp[1] = arr[0];
	dp[2] = arr[0] + arr[1];

	for (int i{ 3 }; i <= N; ++i)
		dp[i] = std::max(dp[i - 3] + arr[i - 2] + arr[i - 1], dp[i - 2] + arr[i - 1]);

	std::cout << dp[N];

	return 0;
}