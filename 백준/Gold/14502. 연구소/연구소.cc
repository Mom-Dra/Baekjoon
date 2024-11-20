#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void SpreadVirus(std::vector<std::vector<int>>& arr, int r, int c)
{
	static std::array<std::pair<int, int>, 4> dn{ { {-1, 0}, {1, 0}, {0, -1}, {0, 1} } };

	arr[r][c] = 3;

	for (const auto& [dr, dc] : dn)
	{
		int nr{ r + dr };
		int nc{ c + dc };

		if (nr >= 0 && nr < arr.size() && nc >= 0 && nc < arr[0].size())
		{
			if (arr[nr][nc] == 0)
			{
				SpreadVirus(arr, nr, nc);
			}
		}
	}
}

int GetSafeArea(std::vector<std::vector<int>>& arr)
{
	for (int i{ 0 }; i < arr.size(); ++i)
	{
		for (int j{ 0 }; j < arr[0].size(); ++j)
		{
			if (arr[i][j] == 2)
				SpreadVirus(arr, i, j);
		}
	}

	int count{ 0 };

	for (const auto& vec : arr)
	{
		for (const auto& num : vec)
		{
			if (num == 0) ++count;
		}
	}

	return count;
}

int MakeMap(std::vector<std::vector<int>>& arr, int r, int c, int count)
{
	if (count == 3)
	{
		std::vector<std::vector<int>> insertedMap = arr;

		return GetSafeArea(insertedMap);
	}

	if (r == arr.size()) return 0;

	int max{ -1 };

	for (int i{ r }; i < arr.size(); ++i)
	{
		for (int j{ i == r ? c : 0 }; j < arr[0].size(); ++j)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;

				int nj{ j + 1 };
				int ni{ i };

				if (nj == arr[0].size())
				{
					nj = 0;

					++ni;
				}

				max = std::max(max, MakeMap(arr, ni, nj, count + 1));

				arr[i][j] = 0;
			}
		}
	}

	return max;
}

int Solve(const std::vector<std::vector<int>>& arr)
{
	std::vector<std::vector<int>> map = arr;

	return MakeMap(map, 0, 0, 0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;

	std::cin >> n >> m;

	std::vector<std::vector<int>> arr(n, std::vector<int>(m, 0));

	for (auto& vec : arr)
	{
		for (auto& num : vec)
		{
			std::cin >> num;
		}
	}

	std::cout << Solve(arr);

	return 0;
}
