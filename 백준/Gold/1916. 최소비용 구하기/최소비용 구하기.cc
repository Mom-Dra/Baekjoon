#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <limits>

int Solve(const std::vector<std::vector<std::pair<int, int>>>& costs, int start, int end)
{
	std::priority_queue<std::pair<int, int>> q;

	// 비용, 시작 위치
	q.emplace(0, start);

	std::vector<int> d(costs.size(), std::numeric_limits<int>::max());

	d[start] = 0;

	while (!q.empty())
	{
		const auto [negDistance, curr] {q.top()};
		q.pop();

		int distance{ -negDistance };

		if (d[curr] < distance) continue;

		for (const auto& [next, cost] : costs[curr])
		{
			int nextDistance{ distance + cost };

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				q.emplace(-nextDistance, next);
			}
		}
	}

	return d[end];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n; // 도시
	int m; // 버스

	// 출발 도시, 도착지 도시, 버스 비용
	std::cin >> n >> m;

	std::vector<std::vector<std::pair<int, int>>> costs(n + 1);

	for (int i{ 0 }; i < m; ++i)
	{
		int start;
		int end;
		int cost;

		std::cin >> start >> end >> cost;

		costs[start].emplace_back(end, cost);
	}

	int start;
	int end;

	std::cin >> start >> end;

	std::cout << Solve(costs, start, end);

	return 0;
}