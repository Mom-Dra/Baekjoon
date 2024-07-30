#include <iostream>
#include <vector>
#include <algorithm>

int main()
{  
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> arr1;
        std::vector<int> arr2;

        for (int j = 0; j < n; ++j)
        {
            int temp;
            std::cin >> temp;

            arr1.push_back(temp);
        }

        int count{ 0 };

        for (int j = 0; j < m; ++j)
        {
            int temp;
            std::cin >> temp;

            arr2.push_back(temp);
        }

        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());

        for (const int& a : arr1)
        {
            for (const int& b : arr2)
            {
                if (a > b) ++count;
                else break;
            }
        }
       
        std::cout << count << '\n';
    }
}