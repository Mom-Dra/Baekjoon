#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <limits>

int Solve(const std::vector<std::vector<int>>& arr, int N, int M)
{
    static std::array<std::pair<int, int>, 4> dn{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };

    std::vector<std::vector<std::vector<bool>>> visited(N, std::vector<std::vector<bool>>(M, std::vector<bool>(2, false)));
        
    std::queue<std::pair<std::pair<int, int>, std::pair<int, bool>>> q;

    q.emplace(std::make_pair(std::make_pair(0, 0), std::make_pair(1, false)));
    visited[0][0][0] = true;

    while (!q.empty())
    {
        auto [pos, info] {q.front()};
        q.pop();

        const auto& [cr, cc] {pos};
        const auto& [count, isBreak] {info};

        if (cr == N - 1 && cc == M - 1)
        {
            return count;
        }

        for (const auto& [dr, dc] : dn)
        {
            int nr{ cr + dr };
            int nc{ cc + dc };

            if (nr >= 0 && nr < N && nc >= 0 && nc < M)
            {
                if (arr[nr][nc] == 0 && !visited[nr][nc][isBreak])
                {
                    q.emplace(std::make_pair(std::make_pair(nr, nc), std::make_pair(count + 1, isBreak)));
                    visited[nr][nc][isBreak] = true;
                }
                else if (arr[nr][nc] == 1 && !isBreak)
                {
                    q.emplace(std::make_pair(std::make_pair(nr, nc), std::make_pair(count + 1, true)));
                    visited[nr][nc][true] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::string tmp;

    std::cin >> N >> M;

    std::vector<std::vector<int>> arr(N, std::vector<int>(M, 0));

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i{ 0 }; i < N; ++i)
    {
        std::getline(std::cin, tmp);

        for (int j{ 0 }; j < M; ++j)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }

    std::cout << Solve(arr, N, M);

    return 0;
}