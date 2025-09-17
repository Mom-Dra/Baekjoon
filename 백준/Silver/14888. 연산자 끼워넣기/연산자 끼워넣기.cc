#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

int calcualte(int num1, int num2, char op)
{
	switch (op)
	{
	case '+':
		return num1 + num2;

	case '-':
		return num1 - num2;

	case '*':
		return num1 * num2;

	case '/':
		return num1 / num2;
	}
}

int solve(const std::vector<int>& arr, const std::vector<char>& op)
{
	int result{ arr[0] };

	for (int i{ 0 }; i < op.size(); ++i)
		result = calcualte(result, arr[i + 1], op[i]);

	return result;
}

char getOp(int num)
{
	switch (num)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	}
}

void backTrack(const std::vector<int>& arr, const std::array<int, 4>& opCount, std::vector<char>& op, std::array<int, 4>& visited, int count, const int& N, int& min, int& max)
{
	if (count == N - 1)
	{
		int result{ solve(arr, op) };
		min = std::min(min, result);
		max = std::max(max, result);
		return;
	}

	// + - * /
	for (int i{ 0 }; i < 4; ++i)
	{
		if (opCount[i] > visited[i])
		{
			op.push_back(getOp(i));
			++visited[i];

			backTrack(arr, opCount, op, visited, count + 1, N, min, max);

			op.pop_back();
			--visited[i];
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> arr(N, 0);

	for (auto& num : arr)
		std::cin >> num;

	std::array<int, 4> opCount{};

	for (auto& num : opCount)
		std::cin >> num;

	int min{ std::numeric_limits<int>::max() }, max{ std::numeric_limits<int>::min() };
	std::vector<char> op;
	std::array<int, 4> visited{};
	op.reserve(N);
	backTrack(arr, opCount, op, visited, 0, N, min, max);

	std::cout << max << '\n' << min;

	return 0;
}