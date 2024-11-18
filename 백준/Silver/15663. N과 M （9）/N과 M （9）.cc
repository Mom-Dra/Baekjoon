#include <iostream>
#include <vector>
#include <algorithm>

void BackTrack(const std::vector<int>& arr, std::vector<bool>& visited, std::vector<int>& answer, int m)
{
	if (answer.size() == m)
	{
		for (const auto& i : answer)
		{
			std::cout << i << ' ';
		}

		std::cout << '\n';
		return;
	}

	int tmp{ 0 };

	for (int i{ 0 }; i < arr.size(); ++i)
	{
		if (!visited[i] && tmp != arr[i])
		{
			tmp = arr[i];

			answer.emplace_back(arr[i]);
			visited[i] = true;

			BackTrack(arr, visited, answer, m);

			answer.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;

	std::cin >> n >> m;

	std::vector<int> arr(n);

	for (auto& num : arr)
	{
		std::cin >> num;
	}

	std::sort(arr.begin(), arr.end());

	std::vector<bool> visited(n, false);
	std::vector<int> answer;

	BackTrack(arr, visited, answer, m);

	return 0;
}