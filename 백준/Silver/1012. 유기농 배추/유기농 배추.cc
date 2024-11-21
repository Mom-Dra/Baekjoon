#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

void BFS(std::vector<std::vector<int>>& arr, int r, int c)
{
    static std::array<std::pair<int, int>, 4> dn {{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    std::queue<std::pair<int, int>> q;
    q.emplace(r, c);
    
    while(!q.empty())
    {
        auto[cr, cc]{q.front()};
        q.pop();
        
        for(const auto&[dr, dc] : dn)
        {
            int nr{ cr + dr };
            int nc{ cc + dc };
            
            if(nr >= 0 && nr < arr.size() && nc >= 0 && nc < arr[0].size())
            {
                if(arr[nr][nc] == 1)
                {
                    q.emplace(nr, nc);
                    arr[nr][nc] = 0;
                }
            }
        }
    }
}

int Solve(std::vector<std::vector<int>>& arr)
{
    int count{0};
    
    for(int i{0}; i < arr.size(); ++i)
    {
        for(int j{0}; j < arr[0].size(); ++j)
        {
            if(arr[i][j] == 1)
            {
                BFS(arr, i, j);
                ++count;
            }
        }
    }
    
    return count;
}

int main()
{
    int T;
    std::cin >> T;
    
    for(int i{0}; i < T; ++i)
    {
        int M, N;
        int K;
        std::cin >> M >> N;
        
        std::vector<std::vector<int>> arr(N, std::vector<int>(M, 0));
        
        std::cin >> K;
        for(int j{0}; j < K; ++j)
        {
            int r, c;
            std::cin >> c >> r;
            
            arr[r][c] = 1;
        }
        
        std::cout << Solve(arr) << '\n';
    }

    return 0;
}