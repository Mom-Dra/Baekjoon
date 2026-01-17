#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> g(N + 1);
	std::vector<int> inDegree(N + 1, 0);

	for (int i{ 0 }; i < M; ++i)
	{
		int A, B;
		std::cin >> A >> B;

		g[A].push_back(B);
		++inDegree[B];
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::vector<int> order;
	order.reserve(N);

	for (int i{ 1 }; i <= N; ++i)
	{
		if (inDegree[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int curr{ pq.top() };
		pq.pop();

		order.push_back(curr);

		for (int next : g[curr])
		{
			--inDegree[next];

			if (inDegree[next] == 0)
				pq.push(next);
		}
	}

	for (const auto& num : order)
		std::cout << num << ' ';

	return 0;
}