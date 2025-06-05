#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void floydWarshall(std::vector<std::vector<int>>& dist, int n)
{
    for (int k{ 0 }; k < n; ++k)
    {
        for (int i{ 0 }; i < n; ++i)
        {
            for (int j{ 0 }; j < n; ++j)
            {
                if (dist[i][k] < std::numeric_limits<int>::max() && dist[k][j] < std::numeric_limits<int>::max())
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int n, m, r;

    std::cin >> n >> m >> r;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    for (int i{ 0 }; i < n; ++i)
        dist[i][i] = 0;

    std::vector<int> items(n);

    for (auto& num : items)
        std::cin >> num;

    for (int i{ 0 }; i < r; ++i)
    {
        int start, end, dis;
        std::cin >> start >> end >> dis;

        dist[start - 1][end - 1] = dis;
        dist[end - 1][start - 1] = dis;
    }

    floydWarshall(dist, n);

    int maxItem{ 0 };

    for (int i{ 0 }; i < n; ++i)
    {
        int item{ 0 };

        for (int j{ 0 }; j < n; ++j)
            if (dist[i][j] <= m) item += items[j];

        maxItem = std::max(maxItem, item);
    }

    std::cout << maxItem;

    return 0;
}