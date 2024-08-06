#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << '*';
        }

        for (int j = 0; j < (n - i) * 2; ++j)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < i; ++j)
        {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << '*';
        }

        for (int j = 0; j < (n - i) * 2; ++j)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < i; ++j)
        {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    return 0;
}