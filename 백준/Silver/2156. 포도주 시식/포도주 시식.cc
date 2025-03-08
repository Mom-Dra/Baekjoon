#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (auto& num : arr)
        std::cin >> num;

    if (n == 1)
    {
        std::cout << arr[0];
        return 0;
    }
    else if (n == 2)
    {
        std::cout << arr[0] + arr[1];
        return 0;
    }

    std::vector<int> dp(n);

    // dp[i] = std::max(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = std::max({ dp[1], dp[0] + arr[2] , arr[1] + arr[2] });

    for (int i{ 3 }; i < n; ++i)
    {
        dp[i] = std::max({ dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i] });
    }

    std::cout << dp[n - 1];

    return 0;
}