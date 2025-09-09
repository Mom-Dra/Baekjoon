#include <iostream>
#include <vector>

bool isSameColor(const std::vector<std::vector<int>>& arr, int r, int c, int length)
{
	int color{ arr[r][c] };

	for (int i{ r }; i < r + length; ++i)
		for (int j{ c }; j < c + length; ++j)
			if (arr[i][j] != color) return false;

	return true;
}

void solve(const std::vector<std::vector<int>>& arr, int r, int c, int length, int& minusCount, int& zeroCount, int& plusCount)
{
	if (isSameColor(arr, r, c, length))
	{
		if (arr[r][c] == -1) ++minusCount;
		else if (arr[r][c] == 0) ++zeroCount;
		else if (arr[r][c] == 1) ++plusCount;

		return;
	}

	int thirdLength{ length / 3 };

	solve(arr, r, c, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r, c + thirdLength, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r, c + thirdLength * 2, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength, c, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength, c + thirdLength, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength, c + thirdLength * 2, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength * 2, c, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength * 2, c + thirdLength, thirdLength, minusCount, zeroCount, plusCount);
	solve(arr, r + thirdLength * 2, c + thirdLength * 2, thirdLength, minusCount, zeroCount, plusCount);
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> arr(N, std::vector<int>(N, 0));

	for (auto& vec : arr)
		for (auto& num : vec)
			std::cin >> num;

	int minusCount{ 0 };
	int zeroCount{ 0 };
	int plusCount{ 0 };

	solve(arr, 0, 0, N, minusCount, zeroCount, plusCount);

	std::cout << minusCount << '\n' << zeroCount << '\n' << plusCount;

	return 0;
}