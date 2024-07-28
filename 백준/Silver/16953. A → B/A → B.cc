#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long a, b;
    std::cin >> a >> b;

    std::queue<std::pair<long long, long long>> q;

    q.emplace(a, 1);

    while (!q.empty())
    {
	    std::pair<long long, long long> curr = q.front();
	    q.pop();

        long long num = curr.first;
	    long long count = curr.second;

	    if (num == b)
	    {
		    std::cout << count;
		    return 0;
	    }

	    long long nextNum = num * 2;

	    if (nextNum <= b)
		    q.emplace(nextNum, count + 1);

	    nextNum = num * 10 + 1;
	
	    if (nextNum <= b)
		    q.emplace(nextNum, count + 1);
    }

    std::cout << -1;
}