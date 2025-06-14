#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(){

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> table(n, std::vector<int>(m, 0));
    std::queue<std::pair<std::pair<int, int>, int>> q;

    int totalCount = 0;
    int cantCount = 0;
    int count = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int tmp;
            std::cin >> tmp;

            if(tmp == - 1) {
                ++cantCount;
                table[i][j] = tmp;
            }
            else{
                if(tmp){
                    table[i][j] = tmp;
                    ++totalCount;
                    ++count;

                    q.push({{i, j}, 0});
                }
                else{
                    ++totalCount;
                }
            }
        }
    }

    if(count == totalCount){
        std::cout << 0;
        return 0;
    }
    else if(cantCount == totalCount){
        std::cout << -1;
        return 0;
    }

    int ans;
    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()){
        std::pair<int, int> pos = q.front().first;
        int x = pos.first;
        int y = pos.second;

        int day = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(table[nx][ny] == 0 && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, day + 1});
                    ++count;
                }
            }
        }

        if(count == totalCount){
            ans = day + 1;
            break;
        }
    }
    
    if(count == totalCount){
        std::cout << ans;
    }
    else{
        std::cout << -1;
    }



    return 0;
}