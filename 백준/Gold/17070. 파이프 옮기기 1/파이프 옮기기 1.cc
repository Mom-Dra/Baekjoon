#include <iostream>
#include <vector>
#include <algorithm>

enum class PipeType
{
	Right,
	Down,
	Diagonal
};

void BackTrack3(const std::vector<std::vector<int>>& arr, int r, int c, int n, const PipeType& type, int& count)
{
	if (r == n - 1 && c == n - 1)
	{
		++count;
		return;
	}

	// 오른쪽 - 0
	if (type != PipeType::Down && c + 1 < n && arr[r][c + 1] != 1)
	{
		BackTrack3(arr, r, c + 1, n, PipeType::Right, count);
	}

	// 아래
	if (type != PipeType::Right && r + 1 < n && arr[r + 1][c] != 1)
	{
		BackTrack3(arr, r + 1, c, n, PipeType::Down, count);
	}

	// 대각선
	if (r + 1 < n && c + 1 < n && arr[r][c + 1] != 1 && arr[r + 1][c] != 1 && arr[r + 1][c + 1] != 1)
	{
		BackTrack3(arr, r + 1, c + 1, n, PipeType::Diagonal, count);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	// 치킨 거리: 집과 가장 가까운 치킨집 사이의 거리
	// 각각의 집은 치킨 거리를 가지고 있다.
	// 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다

	// 0: 빈칸
	// 1: 집
	// 2: 치킨 집

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));

	for (auto& vec : arr)
	{
		for (auto& num : vec)
		{
			std::cin >> num;
		}
	}

	int count{ 0 };

	BackTrack3(arr, 0, 1, n, PipeType::Right, count);

	std::cout << count;

	return 0;
}