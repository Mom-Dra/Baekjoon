#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> arr(n, std::vector<int>(m, 0));

	std::pair<int, int> targetPos;

	for (int i{ 0 }; i < n; ++i)
	{
		for (int j{ 0 }; j < m; ++j)
		{
			std::cin >> arr[i][j];

			if (arr[i][j] == 2)
			{
				auto& [r, c] {targetPos};
				r = i;
				c = j;
			}
		}
	}

	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
	std::queue<std::tuple<int, int, int>> q;
	std::array<std::pair<int, int>, 4> dn{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };

	q.emplace(targetPos.first, targetPos.second, 0);
	visited[targetPos.first][targetPos.second] = true;
	arr[targetPos.first][targetPos.second] = 0;

	while (!q.empty())
	{
		const auto [r, c, count] {q.front()};
		q.pop();

		for (const auto& [dr, dc] : dn)
		{
			int nr{ r + dr };
			int nc{ c + dc };

			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (!visited[nr][nc])
				{
					if (arr[nr][nc] == 1)
					{
						arr[nr][nc] = count + 1;
						visited[nr][nc] = true;
						q.emplace(nr, nc, count + 1);
					}
				}
			}
		}
	}

	for (int i{0}; i < n; ++i)
	{
		for (int j{0}; j < m; ++j)
		{
			if (arr[i][j] == 1 && !visited[i][j])
				std::cout << -1;
			else std::cout << arr[i][j];

			std::cout << ' ';
		}

		std::cout << '\n';
	}

	return 0;
}