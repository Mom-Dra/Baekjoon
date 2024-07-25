#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::queue<int> q;
    int n, k;
    int count{ 0 };

    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    std::cout << '<';

    while (!q.empty())
    {
        for (int i = 0; i < k - 1; ++i)
        {
            int num = q.front();
            q.push(num);
            q.pop();
        }

        ++count;
        if (count != n)
            std::cout << q.front() << ", ";
        else
            std::cout << q.front();

        q.pop();
    }

    std::cout << ">";

    return 0;
}