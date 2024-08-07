#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::vector<int>> arr(n + 1, std::vector<int>(3));

    for (int i = 1; i <= n; ++i)
    {
	    std::cin >> arr[i][0];
	    std::cin >> arr[i][1];
	    std::cin >> arr[i][2];

	    arr[i][0] += std::min(arr[i - 1][1], arr[i - 1][2]);
	    arr[i][1] += std::min(arr[i - 1][0], arr[i - 1][2]);
	    arr[i][2] += std::min(arr[i - 1][0], arr[i - 1][1]);
    }

    std::cout << std::min({ arr[n][0], arr[n][1], arr[n][2] });
}