#include <iostream>
#include <string>
#include <queue>

int main()
{  
    std::queue<int> q;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string op;
        std::cin >> op;

        if (!op.compare("push"))
        {
            int x;
            std::cin >> x;

            q.push(x);
        }
        else if (!op.compare("pop"))
        {
            if (q.empty()) std::cout << -1 << '\n';
            else
            {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (!op.compare("size"))
        {
            std::cout << q.size() << '\n';
        }
        else if (!op.compare("empty"))
        {
            if (q.empty()) std::cout << 1 << '\n';
            else std::cout << 0 << '\n';
        }
        else if (!op.compare("front"))
        {
            if (q.empty()) std::cout << -1 << '\n';
            else std::cout << q.front() << '\n';
        }
        else if (!op.compare("back"))
        {
            if (q.empty()) std::cout << -1 << '\n';
            else std::cout << q.back() << '\n';
        }
    }
}