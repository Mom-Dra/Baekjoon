#include <iostream>
#include <vector>
#include <array>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::array<std::string, 12> arr;

	for (int i = 0; i < 12; ++i)
	{
		std::cin >> arr[i];
	}

	std::array<int, 4> dx = { 0, 0, -1, 1 };
	std::array<int, 4> dy = { -1, 1, 0, 0 };
	
	int answer{ 0 };

	while (true)
	{
		bool minAnswer{ false };
		std::vector<std::vector<bool>> visited(12, std::vector<bool>(6, false));

		for (int i = 0; i < 12; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				char curr = arr[i][j];

				if (!visited[i][j] && curr != '.')
				{
					std::queue<std::pair<int, int>> q;
					std::vector<std::pair<int, int >> poses;
					int cnt{ 1 };

					q.emplace(i, j);
                    poses.emplace_back(i, j);
					visited[i][j] = true;

					while (!q.empty())
					{
						std::pair<int, int> currPos = q.front();
						q.pop();

						for (int k = 0; k < 4; ++k)
						{
							int ny{ currPos.first + dy[k] };
							int nx{ currPos.second + dx[k] };

							if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6)
							{
								if (!visited[ny][nx] && arr[ny][nx] == curr)
								{
									++cnt;
									q.emplace(ny, nx);
									visited[ny][nx] = true;
									poses.emplace_back(ny, nx);
								}
							}
						}
					}

					if (cnt >= 4)
					{
						for (const std::pair<int, int>& pos : poses)
						{
							arr[pos.first][pos.second] = '.';
						}

						if(!minAnswer)
				            ++answer;
						minAnswer = true;
					}
				}


			}
		}

		if (!minAnswer) break;

		for (int j = 0; j < 6; ++j)
		{
			std::vector<char> temp;
			for (int i = 0; i < 12; ++i)
			{
				if (arr[i][j] != '.')
				{
					temp.push_back(arr[i][j]);

					arr[i][j] = '.';
				}
			}

			for (int i = 0; i < temp.size(); ++i)
			{
				arr[12 - temp.size() + i][j] = temp[i];
			}
		}
	}

	std::cout << answer;
	
	return 0;
}