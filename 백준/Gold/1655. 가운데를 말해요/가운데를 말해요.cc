#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    
	int N;
	std::cin >> N;

	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	for (int i{ 0 }; i < N; ++i)
	{
		int num;
		std::cin >> num;

		if (maxHeap.size() <= minHeap.size())
		{
			if (!minHeap.empty() && minHeap.top() < num)
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(num);
			}
			else maxHeap.push(num);
		}
		else
		{
			if (num < maxHeap.top())
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(num);
			}
			else minHeap.push(num);
		}

		std::cout << maxHeap.top() << '\n';
	}

	return 0;
}