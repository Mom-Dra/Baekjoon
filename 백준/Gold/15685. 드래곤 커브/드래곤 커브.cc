#include <iostream>
#include <vector>
#include <array>

void drawDragonCurve(int x, int y, int d, int g, std::array<std::array<bool, 101>, 101>& map)
{
	static std::array<int, 4> dx{ 1, 0, -1, 0 };
	static std::array<int, 4> dy{ 0, -1, 0, 1 };

	std::vector<int> dirs;
	dirs.push_back(d);

	for (int gen{ 0 }; gen < g; ++gen)
	{
		int currSize = dirs.size();

		for (int i{ currSize - 1 }; i >= 0; --i)
		{
			dirs.push_back((dirs[i] + 1) % 4);
		}
	}

	map[y][x] = true;

	for (int dir : dirs)
	{
		x += dx[dir];
		y += dy[dir];

		if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
			map[y][x] = true;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::array<std::array<bool, 101>, 101> map{};

	int N;
	std::cin >> N;

	for (int i{ 0 }; i < N; ++i)
	{
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;

		drawDragonCurve(x, y, d, g, map);
	}

	int count{ 0 };

	for (int y{ 0 }; y < 100; ++y)
	{
		for (int x{ 0 }; x < 100; ++x)
		{
			if (map[y][x] && map[y + 1][x] && map[y][x + 1] && map[y + 1][x + 1])
				++count;
		}
	}

	std::cout << count << '\n';

	return 0;
}