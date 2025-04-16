#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <limits>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& g, int start)
{
	constexpr int INF{ 100000000 };
    
	std::vector<int> d(g.size(), INF);
	d[start] = 0;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty())
	{
		const auto [distance, curr] {pq.top()};
		pq.pop();

		if (d[curr] < distance) continue;

		for (const auto& [next, cost] : g[curr])
		{
			int nextDistance{ distance + cost };

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.emplace(nextDistance, next);
			}
		}
	}

	return d;
}

int solve(const std::vector<std::vector<std::pair<int, int>>>& g, const std::vector<std::vector<std::pair<int, int>>>& g2, int X, const int N)
{
	std::vector<int> d1{ dijkstra(g, X) };
	std::vector<int> d2{ dijkstra(g2, X) };

	int max{ std::numeric_limits<int>::min() };

	for (int i{ 0 }; i < N; ++i)
	{
		int distance{ d1[i] + d2[i] };
		max = std::max(max, distance);
	}

	return max;
}

int main()
{
	int N, M, X;
	std::cin >> N >> M >> X;

	std::vector<std::vector<std::pair<int, int>>> g(N, std::vector<std::pair<int, int>>());
	std::vector<std::vector<std::pair<int, int>>> g2(N, std::vector<std::pair<int, int>>());

	for (int i{ 0 }; i < M; ++i)
	{
		int A, B, T;
		std::cin >> A >> B >> T;

		g[A - 1].emplace_back(B - 1, T);
		g2[B - 1].emplace_back(A - 1, T);
	}

	std::cout << solve(g, g2, X - 1, N);

	return 0;
}