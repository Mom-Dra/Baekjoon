#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int GetChikenDistance(const std::vector<std::vector<int>>& map, int r, int c)
{
	int min{ std::numeric_limits<int>::max() };

	for (int i{ 0 }; i < map.size(); ++i)
	{
		for (int j{ 0 }; j < map[0].size(); ++j)
		{
			if (map[i][j] == 2)
			{
				int distance{ std::abs(r - i) + std::abs(c - j) };
				min = std::min(min, distance);
			}
		}
	}

	return min;
}

int GetCityChikenDistance(const std::vector<std::vector<int>>& map)
{
	int distance{ 0 };

	for (int i{ 0 }; i < map.size(); ++i)
	{
		for (int j{ 0 }; j < map[0].size(); ++j)
		{
			if (map[i][j] == 1)
			{
				distance += GetChikenDistance(map, i, j);
			}
		}
	}

	return distance;
}

int SelectChiken(std::vector<std::vector<int>>& map, int r, int c, int count, int m)
{
	// m개만 남긴다!

	if (count == m)
	{
		return GetCityChikenDistance(map);
	}

	int min{ std::numeric_limits<int>::max() };

	for (int i{ r }; i < map.size(); ++i)
	{
		for (int j{ i == r ? c : 0 }; j < map[0].size(); ++j)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 0;

				int ni{ i };
				int nj{ j + 1 };
				
				if (nj == map[0].size())
				{
					nj = 0;
					++ni;
				}

				min = std::min(min, SelectChiken(map, ni, nj, count + 1, m));

				map[i][j] = 2;
			}
		}
	}

	return min;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));

	int chikenCount{ 0 };

	for (auto& vec : arr)
	{
		for (auto& num : vec)
		{
			std::cin >> num;

			if (num == 2) ++chikenCount;
		}
	}

	std::cout << SelectChiken(arr, 0, 0, 0, chikenCount - m);

	return 0;
}