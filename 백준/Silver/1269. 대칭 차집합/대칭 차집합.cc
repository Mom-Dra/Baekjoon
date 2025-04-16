#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int A, B;
    std::cin >> A >> B;

    std::unordered_set<int> uSet;

    for (int i{ 0 }; i < A + B; ++i)
    {
        int num;
        std::cin >> num;

        if (uSet.find(num) == uSet.end())
            uSet.insert(num);
        else
            uSet.erase(num);
    }

    std::cout << uSet.size();

    return 0;
}