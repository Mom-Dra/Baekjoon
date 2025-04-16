#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    std::vector<int> dp(N, 1);
    for(auto& num : arr)
        std::cin >> num;

    int max{0};

    for(int i{0}; i < N; ++i)
    {
        for(int j{0}; j < i; ++j)
        {
            if(arr[i] < arr[j])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }

        max = std::max(dp[i], max);
    }

    std::cout << max;

    return 0;
}