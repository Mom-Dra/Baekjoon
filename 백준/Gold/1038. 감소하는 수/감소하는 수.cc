#include <iostream>
#include <queue>

int main()
{
	int N;

	std::cin >> N;

	std::queue<long long> q;

	for (int i{ 0 }; i < 10; ++i)
	{
		q.push(i);
	}

	int count{ 0 };
	long long answer{ -1 };

	while (!q.empty())
	{
		long long num{ q.front() };
		q.pop();

		if (count == N)
		{
			answer = num;
			break;
		}

		++count;

		for (int i{ 0 }; i <= num % 10 - 1; ++i)
		{
			q.push(num * 10 + i);
		}
	}

	std::cout << answer;

	return 0;
}