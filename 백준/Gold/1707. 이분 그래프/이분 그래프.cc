#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    
	int T;
	std::cin >> T;

	for (int t{ 0 }; t < T; ++t)
	{
		int V, E;
		std::cin >> V >> E;

		std::vector<std::vector<int>> g(V);

		for (int i{ 0 }; i < E; ++i)
		{
			int u, v;
			std::cin >> u >> v;

			g[u - 1].push_back(v - 1);
			g[v - 1].push_back(u - 1);
		}

		std::vector<int> visited(V, 0);
		bool trigger{ false };

		for (int start{ 0 }; start < V; ++start)
		{
			if (visited[start] != 0) continue;

			std::queue<int> q;
			q.push(start);

			visited[start] = 1;

			while (!q.empty())
			{
				int curr{ q.front() };
				q.pop();

				int currColor{ visited[curr] };

				for (int next : g[curr])
				{
					if (visited[next] == 0)
					{
						q.push(next);
						visited[next] = -currColor;
					}
					else if (visited[next] == currColor)
					{
						trigger = true;
						break;
					}
				}

				if (trigger)
					break;
			}

			if (trigger)
				break;
		}

		std::cout << (trigger ? "NO" : "YES") << '\n';
	}

	return 0;
}