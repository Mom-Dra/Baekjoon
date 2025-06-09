#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include <set>

void BFS(const std::vector<std::vector<int>>& g, int start)
{
    std::queue<int> q;
    std::vector<bool> visited(g.size(), false);

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int curr{ q.front() };
        q.pop();

        std::cout << curr + 1 << ' ';

        for (const int next : g[curr])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void DFS(const std::vector<std::vector<int>>& g, int curr, std::vector<bool>& visited)
{
    if (visited[curr]) return;

    visited[curr] = true;
    std::cout << curr + 1 << ' ';

    for (const int next : g[curr])
    {
        DFS(g, next, visited);
    }
}

void DFS(const std::vector<std::vector<int>>& g, int curr)
{
    std::vector<bool> visited(g.size(), false);

    DFS(g, curr, visited);
}

int main()
{
    int N, M, V;
    std::cin >> N >> M >> V;

    std::vector<std::vector<int>> g(N);

    for (int i{ 0 }; i < M; ++i)
    {
        int start, end;
        std::cin >> start >> end;

        g[start - 1].push_back(end - 1);
        g[end - 1].push_back(start - 1);
    }

    for (auto& vec : g)
        std::sort(vec.begin(), vec.end());

    DFS(g, V - 1);

    std::cout << '\n';
    
    BFS(g, V - 1);

    return 0;
}