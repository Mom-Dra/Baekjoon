#include <iostream>
#include <vector>
#include <algorithm>
int dfs(int curr, std::vector<bool>& visited, std::vector<int> graph[]);

int main(){

    int n;
    int m;

    std::cin >> n;
    std::cin >> m;

    std::vector<int> graph[n];

    for(int i = 0; i < m; ++i){
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    std::vector<bool> visited(n, false);

    std::cout << dfs(0, visited, graph);

    return 0;
}

int dfs(int curr, std::vector<bool>& visited, std::vector<int> graph[]){
    visited[curr] = true;
    int count = 0;
    
    for(std::vector<int>::iterator iter = graph[curr].begin(); iter != graph[curr].end(); ++iter){
        if(!visited[*iter]){
            ++count;
            count += dfs(*iter, visited, graph);
        }
    }

    return count;
}