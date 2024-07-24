#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr(3);

    for (int i = 0; i < 3; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());


    for (int i = 0; i < 3; ++i)
    {
        std::cout << arr[i] << ' ';
    }

    return 0;
}