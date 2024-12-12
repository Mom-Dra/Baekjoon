#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int Solve(const std::vector<int>& arr, const int N, const int S)
{
    int left{0};
    int right{1};

    bool canSum{false};
    int min{std::numeric_limits<int>::max()};
    int sum{arr[0]};

    while(left < right)
    {
        if(sum >= S)
        {
            canSum = true;
            
            min = std::min(min, right - left);

            sum -= arr[left];
            ++left;
        }
        else
        {
            if(right == N) break;   
            sum += arr[right];
            ++right;
        }
    }
            
    if(!canSum) return 0;
    return min;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, S;
    std::cin >> N >> S;

    std::vector<int> arr(N);
    
    for(auto& num : arr)
        std::cin >> num;
    
    std::cout << Solve(arr, N, S);

    return 0;
}