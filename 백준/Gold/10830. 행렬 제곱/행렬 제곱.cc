#include <iostream>
#include <vector>
#include <unordered_map>

long long Dot(const std::vector<int>& a, const std::vector<int>& b)
{
    long long val{ 0 };

    for (std::size_t i{ 0 }; i < a.size(); ++i)
        val += (a[i] * b[i]);

    return val;
}

std::vector<int> GetColVec(const std::vector<std::vector<int>>& b, int col, int N)
{
    std::vector<int> arr(N);

    for (int i{ 0 }; i < N; ++i)
        arr[i] = b[i][col];

    return arr;
}

std::vector<std::vector<int>> Mul(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b, int N)
{
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    for (int i{ 0 }; i < N; ++i)
    {
        for (int j{ 0 }; j < N; ++j)
        {
            result[i][j] = Dot(a[i], GetColVec(b, j, N)) % 1000;
        }
    }

    return result;
}

std::unordered_map<long long, std::vector<std::vector<int>>> uMap;
std::vector<std::vector<int>> Solve(const std::vector<std::vector<int>>& A, int N, long long B)
{
    if (uMap.find(B) != uMap.end()) return uMap[B];

    if (B % 2 == 0) uMap.emplace(B, Mul(Solve(A, N, B / 2), Solve(A, N, B / 2), N));
    else uMap.emplace(B, Mul(Mul(Solve(A, N, B / 2), Solve(A, N, B / 2), N), A, N));

    return uMap[B];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    long long B;
    std::cin >> N >> B;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));

    for (int i{ 0 }; i < N; ++i)
    {
        for (int j{ 0 }; j < N; ++j)
        {
            std::cin >> A[i][j];

            A[i][j] %= 1000;
        }
    }

    uMap.emplace(1, A);

    std::vector<std::vector<int>> result{ Solve(A, N, B) };

    for (const auto& vec : result)
    {
        for (const auto& num : vec)
            std::cout << num << ' ';

        std::cout << '\n';
    }

    return 0;
}