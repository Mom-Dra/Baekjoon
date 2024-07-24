#include <iostream>
#include <list>

int main()
{
    std::list<char> arr;
    std::list<char>::iterator it;

    std::string s;
    int n;

    std::cin >> s;
    std::cin >> n;

    for (char c : s)
    {
        arr.push_back(c);
    }

    it = arr.end();

    for (int i = 0; i < n; ++i)
    {
        char c;

        std::cin >> c;

        switch (c)
        {
        case 'L':
            if (it != arr.begin()) --it;
            break;
        case 'D':
            if (it != arr.end()) ++it;
            break;
        case 'B':
            if (it != arr.begin()) it = arr.erase(--it);
            break;
        case 'P':
            std::cin >> c;
            arr.insert(it, c);
            break;
        }
    }

    for (char d : arr)
    {
        std::cout << d;
    }

    return 0;
}