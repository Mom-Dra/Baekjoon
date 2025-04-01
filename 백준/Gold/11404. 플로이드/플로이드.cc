#include <iostream>
#include <vector>

constexpr int INF{ 1000000000 };

void printVector(const std::vector<std::vector<int>>& arr)
{
    for (const auto& vec : arr)
    {
        for (const auto& num : vec)
        {
            if (num == INF) std::cout << "0 ";
            else std::cout << num << ' ';
        }

        std::cout << '\n';
    }
}

void floydWarshall(const std::vector<std::vector<int>>& arr, int n)
{
    std::vector<std::vector<int>> d{ arr };

    for (int k{ 0 }; k < n; ++k)
        for (int i{ 0 }; i < n; ++i)
            for (int j{ 0 }; j < n; ++j)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printVector(d);
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(n, INF));

    for (int i{ 0 }; i < n; ++i)
        arr[i][i] = 0;

    for (int i{ 0 }; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (c < arr[a - 1][b - 1])
            arr[a - 1][b - 1] = c;
    }

    floydWarshall(arr, n);

    return 0;
}