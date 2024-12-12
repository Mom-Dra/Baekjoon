#include <iostream>
#include <vector>
#include <algorithm>

int Combination(int N, int M)
{
    int r{std::min(N, M - N)};

    int val{1};

    for(int i{1}; i <= r; ++i)
    {
        val *= (M--);
        val /= i;
    }

    return val;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for(int i{0}; i < T; ++i)
    {
        int N, M;
        std::cin >> N >> M;

        std::cout << Combination(N, M) << '\n';
    }

    return 0;
}