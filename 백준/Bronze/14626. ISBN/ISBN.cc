#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    bool isTriple{ false };
    bool isTargetTriple;
    int num{ 0 };

    for (const char c : s)
    {
        if (c == '*') isTargetTriple = isTriple;
        else if (isTriple) num += (3 * (c - '0'));
        else num += (c - '0');

        isTriple = !isTriple;
    }

    int answer;

    for (int i{ 0 }; i < 10; ++i)
    {
        int sum{ num };

        sum += isTargetTriple ? 3 * i : i;

        if (sum % 10 == 0)
        {
            std::cout << i;
            return 0;
        }
    }
}