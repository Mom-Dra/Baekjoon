#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

void SetRectangle(std::vector<std::vector<bool>>& arr, int x1, int y1, int x2, int y2)
{
    for(int i{y1}; i < y2; ++i)
    {
        for(int j{x1}; j < x2; ++j)
        {
            arr[i][j] = true;
        }
    }
}

int BFS(std::vector<std::vector<bool>>& arr, int r, int c)
{
    static std::array<std::pair<int, int>, 4> dn{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    int area{1};
    
    std::queue<std::pair<int, int>> q;
    q.emplace(r, c);
    arr[r][c] = true;
    
    while(!q.empty())
    {
        auto [cr, cc]{q.front()};
        q.pop();
        
        for(const auto[dr, dc] : dn)
        {
            int nr {cr + dr};
            int nc {cc + dc};
            
            if(nr >= 0 && nr < arr.size() && nc >=0 && nc < arr[0].size())
            {
                if(!arr[nr][nc])
                {
                    q.emplace(nr, nc);
                    arr[nr][nc] = true;
                    ++area;
                }
            }
        }
    }
    
    return area;
}

void Solve(std::vector<std::vector<bool>>& arr)
{
    int count{0};
    
    std::vector<int> areas;
    
    for(int i{0}; i < arr.size(); ++i)
    {
        for(int j{0}; j < arr[0].size(); ++j)
        {
            if(!arr[i][j])
            {
                ++count;
                areas.emplace_back(BFS(arr, i, j));
            }
        }
    }
    
    std::sort(areas.begin(), areas.end());
    
    std::cout << count << '\n';
    for(const auto& num : areas)
    {
        std::cout << num << ' ';
    }
}

int main()
{
    int M; // 세로
    int N; // 가로
    int K; // 직사 각형 수
    
    std::cin >> M >> N >> K;
    
    std::vector<std::vector<bool>> arr(M, std::vector<bool>(N, false));
    
    for(int i{0}; i < K; ++i)
    {
        int x1, y1;
        int x2, y2;
        
        std::cin >> x1 >> y1;
        std::cin >> x2 >> y2;
        
        SetRectangle(arr, x1, y1, x2, y2);
    }
    
    Solve(arr);
    
    return 0;
}