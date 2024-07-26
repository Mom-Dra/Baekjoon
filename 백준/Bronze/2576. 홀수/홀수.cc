#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int minVal{ 101 };
    int sum{ 0 };

    bool trigger{ false };

    for (int i = 0; i < 7; ++i)
    {
        int num;
        std::cin >> num;

        if (num % 2 == 1)
        {
            trigger = true;

            sum += num;
            minVal = std::min(minVal, num);
        }
    }

    if (trigger)
        std::cout << sum << '\n' << minVal;
    else
        std::cout << -1;

    return 0;
}