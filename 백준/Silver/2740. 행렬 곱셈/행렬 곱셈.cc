#include <iostream>
#include <vector>

int dot(std::vector<int>& a, std::vector<int>& b)
{
    int sum{ 0 };

    for (size_t i{ 0 }; i < a.size(); ++i)
        sum += a[i] * b[i];

    return sum;
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> m(N, std::vector<int>(M, 0));

    for (auto& vec : m)
        for (auto& num : vec)
            std::cin >> num;

    int K;
    std::cin >> M >> K;

    std::vector<std::vector<int>> m2(M, std::vector<int>(K, 0));

    for (auto& vec : m2)
        for (auto& num : vec)
            std::cin >> num;
    
    for (int i{ 0 }; i < N; ++i)
    {
        for (int j{ 0 }; j < K; ++j)
        {
            std::vector<int> b;
            b.reserve(M);

            for (int k{ 0 }; k < M; ++k)
                b.push_back(m2[k][j]);

            std::cout << dot(m[i], b) << ' ';
        }

        std::cout << '\n';
    }

    return 0;
}