#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // 그 그림의 개수와
    // 그 그림 중 넓이가 가장 넓은 것의 넓이
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(m));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    int count{ 0 };
    int max{ 0 };

    std::array<int, 4> dx = { 0, 0, -1, 1 };
    std::array<int, 4> dy = { -1, 1, 0, 0 };
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                int size{ 0 };

                ++count;

                std::queue<std::pair<int, int> > q;
                visited[i][j] = true;
                q.emplace(i, j);

                while (!q.empty())
                {
                    std::pair<int, int> curr{ q.front() };
                    q.pop();

                    ++size;

                    for (int k = 0; k < 4; ++k)
                    {
                        int ny = curr.first + dy[k];
                        int nx = curr.second + dx[k];

                        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                        {
                            if (arr[ny][nx] == 1 && !visited[ny][nx])
                            {
                                visited[ny][nx] = true;
                                q.emplace(ny, nx);
                            }
                        }
                    }
                }

                max = std::max(max, size);
            }
        }
    }

    std::cout << count << '\n';
    std::cout << max;

    return 0;
}