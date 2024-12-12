#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int Solve(const std::vector<int>& arr, const int N)
{
    int sum{0};
    int max{std::numeric_limits<int>::min()};

    for(int i{0}; i < N; ++i)
    {
        sum += arr[i];

        if(sum > max) max = sum;
        if(sum < 0) sum = 0;
    }

    return max;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for(auto& num : arr)
        std::cin >> num;

    std::cout << Solve(arr, n);

    return 0;
}