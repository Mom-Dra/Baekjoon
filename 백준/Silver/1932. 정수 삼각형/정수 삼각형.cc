#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
   
    std::cin >> n;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i{ 1 }; i <= n; ++i)
    {
        for (int j{ 1 }; j <= i; ++j)
        {
            int num;
            std::cin >> num;

            dp[i][j] = std::max(dp[i - 1][j] + num, dp[i - 1][j - 1] + num);
        }
    }

    auto max{ std::max_element(dp[n].begin(), dp[n].end()) };

    std::cout << *max;

    return 0;
}
