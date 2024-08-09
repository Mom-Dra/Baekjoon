#include <iostream>
#include <vector>

void SetVisit(std::vector<std::vector<int>>& arr, int curr, int col, int n, int set)
{
	int extra{ 0 };

	for (int i = curr; i < n; ++i,  ++extra)
	{
		arr[i][col] += set;
		
		if (col + extra < n)
			arr[i][col + extra] += set;

		if (col - extra >= 0)
			arr[i][col - extra] += set;
	}
}

void NQueen(std::vector<std::vector<int>>& arr, int curr, int n, int& sum)
{
	if (curr == n)
	{
		++sum;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		// visited set
		if (arr[curr][i] == 0)
		{
			SetVisit(arr, curr, i, n, 1);

			NQueen(arr, curr + 1, n, sum);

			SetVisit(arr, curr, i, n, -1);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));

	int sum{ 0 };
	NQueen(arr, 0, n, sum);

	std::cout << sum;
}