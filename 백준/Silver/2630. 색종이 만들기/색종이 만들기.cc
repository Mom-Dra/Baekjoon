#include <iostream>
#include <vector>

void solve(const std::vector<std::vector<int>>& arr, int r, int c, int length, int& whiteCount, int& blueCount)
{
	int color{ arr[r][c] };
	bool trigger{ false };

	for (int i{ r }; i < r + length; ++i)
	{
		for (int j{ c }; j < c + length; ++j)
		{
			if (arr[i][j] != color)
				trigger = true;
		}

		if (trigger) break;
	}

	if (trigger)
	{
		solve(arr, r, c, length / 2, whiteCount, blueCount);
		solve(arr, r, c + length / 2, length / 2, whiteCount, blueCount);
		solve(arr, r + length / 2, c, length / 2, whiteCount, blueCount);
		solve(arr, r + length / 2, c + length / 2, length / 2, whiteCount, blueCount);
	}
	else
	{
		if (color == 0) ++whiteCount;
		else ++blueCount;
	}
}

int main()
{
	int N;
	std::cin >> N;
    
	std::vector<std::vector<int>> arr(N, std::vector<int>(N, 0));

	for (auto& vec : arr)
		for (auto& num : vec)
			std::cin >> num;

	int whiteCount{ 0 };
	int blueCount{ 0 };

	solve(arr, 0, 0, N, whiteCount, blueCount);

	std::cout << whiteCount << '\n' << blueCount;

	return 0;
}