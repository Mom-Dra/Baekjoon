#include <iostream>
#include <vector>
#include <numeric>

int GetParent(std::vector<int>& parent, int x)
{
    if (parent[x] == x) return x;
    return parent[x] = GetParent(parent, parent[x]);
}

void UnionParent(std::vector<int>& parent, int a, int b)
{
    a = GetParent(parent, a);
    b = GetParent(parent, b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool FindParent(std::vector<int>& parent, int a, int b)
{
    a = GetParent(parent, a);
    b = GetParent(parent, b);

    return a == b;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int truthCount;
    std::cin >> truthCount;

    std::vector<int> truthNumbers(truthCount);

    for (auto& truthNumber : truthNumbers)
        std::cin >> truthNumber;

    std::vector<int> parent(n + 1);
    std::iota(parent.begin(), parent.end(), 0);

    std::vector<std::vector<int>> parties(m);

    for (int i{ 0 }; i < m; ++i)
    {
        int count;
        std::cin >> count;

        int prev;
        std::cin >> prev;

        parties[i].push_back(prev);

        for (int j{ 1 }; j < count; ++j)
        {
            int num;
            std::cin >> num;

            parties[i].push_back(num);

            UnionParent(parent, prev, num);

            prev = num;
        }
    }

    std::vector<bool> knowTruth(n + 1, false);

    for (const auto& truthNumber : truthNumbers)
    {
        knowTruth[truthNumber] = true;

        for (int i{ 1 }; i <= n; ++i)
        {
            if (FindParent(parent, truthNumber, i))
                knowTruth[i] = true;
        }
    }

    int count{ 0 };

    for (const auto& party : parties)
    {
        bool hasKnowTruth{ false };

        for (const auto& num : party)
        {
            if (knowTruth[num])
            {
                hasKnowTruth = true;
                break;
            }
        }

        if (!hasKnowTruth)
            ++count;
    }

    std::cout << count;

    return 0;
}