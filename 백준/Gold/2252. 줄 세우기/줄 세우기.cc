#include <iostream>
#include <vector>

void topologicalSort(const std::vector<std::vector<int>>& g, std::vector<int>& order, std::vector<bool>& visited, int curr, const int N)
{
	visited[curr] = true;

	for (int next : g[curr])
		if (!visited[next])
			topologicalSort(g, order, visited, next, N);

	order.push_back(curr);
}

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& g, const int N)
{
	std::vector<bool> visited(N + 1, false);
	std::vector<int> order;
	order.reserve(N);

	for (int i{ 1 }; i <= N; ++i)
	{
		if (!visited[i])
			topologicalSort(g, order, visited, i, N);
	}

	return order;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> g(N + 1);

	for (int i{ 0 }; i < M; ++i)
	{
		int A, B;
		std::cin >> A >> B;

		g[A].push_back(B);
	}

	std::vector<int> result;
	result.reserve(N);

	std::vector<int> order{ topologicalSort(g, N) };

	for (auto it{ order.rbegin() }; it != order.rend(); ++it)
		std::cout << *it << ' ';

	return 0;
}