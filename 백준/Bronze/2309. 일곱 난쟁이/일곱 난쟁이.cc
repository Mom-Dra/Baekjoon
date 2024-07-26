#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 9

void Solve(const std::vector<int>& arr, std::vector<int>& result , std::vector<bool>& visited, int sum, int count, bool& isFound)
{
    if (sum > 100)
    {
        return;
    }
    else if (count == 7)
    {
        if (sum == 100) // 정답
        {
            isFound = true;

            std::sort(result.begin(), result.end());

            for (int n : result)
            {
                std::cout << n << '\n';
            }
        }

        return;
    }
    else if (isFound) return;

    for (int i = 0; i < SIZE; ++i)
    {
        if (!visited[i])
        {
            result.push_back(arr[i]);
            visited[i] = true;

            Solve(arr, result, visited, sum + arr[i], count + 1, isFound);

            visited[i] = false;
            result.pop_back();
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> arr(SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        std::cin >> arr[i];
    }

    std::vector<int> result;
    result.reserve(7);

    std::vector<bool> visited(SIZE);
    bool isFound{ false };
    
    Solve(arr, result, visited, 0, 0, isFound);

    return 0;
}