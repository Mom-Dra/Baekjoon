#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;
    std::vector<int> arr;
    int n, k;
    int count{ 0 };

    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    
    while (!q.empty())
    {
        ++count;

        int num = q.front();
        q.pop();

        if (count == k)
        {
            arr.push_back(num);

            count = 0;
        }
        else
        {
            q.push(num);
        }
    }

    std::cout << '<';

    for (int i = 0; i < n - 1; ++i)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << arr[n - 1];

    std::cout << ">";

    return 0;
}