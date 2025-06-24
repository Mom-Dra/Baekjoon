#include <iostream>
#include <vector>

int main()
{
    int N;
  
    std::cin >> N;

    std::vector<int> arr;
    arr.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int n;
        std::cin >> n;
        arr.push_back(n);
    }

    std::vector<int> dp(1005, 1);

    int max{ 1 };

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        max = std::max(max, dp[i]);
    }       
                         
    std::cout << max;

    return 0;
}