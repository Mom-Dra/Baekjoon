#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>
#include <limits>

int solve(const std::vector<std::vector<char>> &arr, int r, int c)
{
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
    std::vector<std::vector<int>> dist(arr.size(), std::vector<int>(arr[0].size(), std::numeric_limits<int>::max()));
    std::array<std::pair<int, int>, 4> dn{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    int minDist{std::numeric_limits<int>::max()};

    pq.emplace(0, r, c);
    dist[r][c] = 0;

    while (!pq.empty())
    {
        auto [cDist, cr, cc]{pq.top()};
        pq.pop();

        for (const auto &[dr, dc] : dn)
        {
            int nDist{0};
            int nr{cr + dr};
            int nc{cc + dc};

            while (true)
            {
                if (!(nr >= 0 && nr < arr.size() && nc >= 0 && nc < arr[0].size()))
                    break;

                if (arr[nr][nc] == 'R')
                {
                    int nextDist{cDist + nDist};

                    if (nextDist < dist[nr - dr][nc - dc])
                    {
                        pq.emplace(nextDist, nr - dr, nc - dc);
                        dist[nr - dr][nc - dc] = nextDist;
                    }

                    break;
                }
                else if (arr[nr][nc] == 'E')
                {
                    minDist = std::min(minDist, cDist + nDist);
                    break;
                }
                else if (arr[nr][nc] == 'H')
                {
                    break;
                }
                else
                {
                    nDist += arr[nr][nc] - '0';
                }

                nr += dr;
                nc += dc;
            }
        }
    }

    return minDist == std::numeric_limits<int>::max() ? -1 : minDist;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int W, H;
    std::cin >> W >> H;

    std::vector<std::vector<char>> arr(H, std::vector<char>(W));

    int r, c;

    for (int i{0}; i < H; ++i)
    {
        for (int j{0}; j < W; ++j)
        {
            std::cin >> arr[i][j];

            if (arr[i][j] == 'T')
            {
                r = i;
                c = j;
                arr[i][j] = '0';
            }
        }
    }

    std::cout << solve(arr, r, c);

    return 0;
}