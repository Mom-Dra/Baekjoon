#include <iostream>
#include <vector>
#include <array>
#include <queue>

std::vector<std::pair<int, int>> findMeltingCheeze(const std::vector<std::vector<int>>& arr)
{
    static std::array<std::pair<int, int>, 4> dn {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    std::vector<std::vector<bool>> visited(arr.size(), std::vector<bool>(arr[0].size(), false));
    
    std::vector<std::pair<int, int>> meltingCheezes;
    std::vector<std::vector<bool>> cheezeVisited(arr.size(), std::vector<bool>(arr[0].size(), false));

    visited[0][0] = true;

    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);

    while(!q.empty())
    {
        const auto& [r, c]{q.front()};
        q.pop();

        for(const auto& [dr, dc] : dn)
        {
            int nr{r + dr};
            int nc{c + dc};

            if(nr >= 0 && nr < arr.size() && nc >= 0 && nc < arr[0].size())
            {
                if(arr[nr][nc] == 1)
                {
                    if(cheezeVisited[nr][nc]) meltingCheezes.emplace_back(nr, nc);
                    else cheezeVisited[nr][nc] = true;
                }
                else if(!visited[nr][nc])
                {
                    q.emplace(nr, nc);
                    visited[nr][nc] = true;
                }
            }
        }
    }

    return meltingCheezes;
}

void meltCheeze(std::vector<std::vector<int>>& arr, const std::vector<std::pair<int, int>>& meltingCheezes)
{
	for (const auto& [r, c] : meltingCheezes)
		arr[r][c] = 0;
}

bool isAllCheezeMelt(const std::vector<std::vector<int>>& arr)
{
	for (const auto& vec : arr)
		for (const auto& num : vec)
			if (num == 1) return false;

	return true;
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> arr(N, std::vector<int>(M, 0));

	for (auto& vec : arr)
		for (auto& num : vec)
			std::cin >> num;

	int time{ 0 };

	while (!isAllCheezeMelt(arr))
	{
		++time;
		meltCheeze(arr, findMeltingCheeze(arr));
	}

	std::cout << time;

	return 0;
}