#include <iostream>
#include <vector>
#include <array>

int main()
{
	int N;
	std::cin >> N;

	std::array<std::array<bool, 101>, 101> visited{};
	std::array<std::pair<int, int>, 4> dn{ {{ 1, 0 }, {0, -1}, {-1, 0}, {0, 1}} };

	for (int i{ 0 }; i < N; ++i)
	{
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;

		std::vector<std::pair<int, int>> vertices;
		vertices.emplace_back(x, y);
		visited[x][y] = true;

		std::pair<int, int> referencePoint{ x, y };

		referencePoint.first = x + dn[d].first;
		referencePoint.second = y + dn[d].second;

		vertices.emplace_back(referencePoint);
		visited[referencePoint.first][referencePoint.second] = true;

		for (int j{ 0 }; j < g; ++j)
		{
			std::vector<std::pair<int, int>> tmpVertices{ vertices };

			for (auto& [x, y] : tmpVertices)
			{
				x -= referencePoint.first;
				y -= referencePoint.second;

				int rotatedX = -y;
				int rotatedY = x;

				x = rotatedX + referencePoint.first;
				y = rotatedY + referencePoint.second;
			}

			for (size_t i{ 0 }, j{ tmpVertices.size() - 1 }; i < tmpVertices.size(); ++i, --j)
			{
				const auto& [x, y] {tmpVertices[j]};

				visited[x][y] = true;
				vertices.emplace_back(x, y);
			}

			referencePoint = tmpVertices[0];
		}
	}

	int count{ 0 };

	for (int i{ 0 }; i < 100; ++i)
	{
		for (int j{ 0 }; j < 100; ++j)
		{
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
				++count;
		}
	}

	std::cout << count;

	return 0;
}