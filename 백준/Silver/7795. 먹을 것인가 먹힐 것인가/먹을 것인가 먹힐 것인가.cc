#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>

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

        std::vector<int> s1;
        s1.reserve(n);
        std::vector<int> s2;
        s2.reserve(m);

        for (int j = 0; j < n; ++j)
        {
            int temp;
            std::cin >> temp;

            s1.push_back(temp);
        }

        int count{ 0 };

        for (int j = 0; j < m; ++j)
        {
            int temp;
            std::cin >> temp;

            s2.push_back(temp);
        }

        std::sort(s2.begin(), s2.end());

        for (const int& k : s1)
        {
            std::vector<int>::iterator it = std::lower_bound(s2.begin(), s2.end(), k);
            count += std::distance(s2.begin(), it);
        }

        std::cout << count << '\n';
    }
}