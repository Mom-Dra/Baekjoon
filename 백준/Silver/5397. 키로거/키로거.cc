#include <iostream>
#include <algorithm>
#include <list>

int main()
{
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::list<char> arr;
        std::list<char>::iterator iter = arr.begin();
       
        std::cin >> s;
    
        for (int j = 0; j < s.size(); ++j)
        {
            switch (s[j])
            {
            case '<':
                if (iter != arr.begin()) --iter;
                break;
            case '>':
                if (iter != arr.end()) ++iter;
                break;
            case '-':
                if (iter != arr.begin()) iter = arr.erase(--iter);
                break;
            default:
                iter = arr.insert(iter, s[j]);
                ++iter;
                break;
            }
        }

        for (iter = arr.begin(); iter != arr.end(); ++iter)
        {
            std::cout << *iter;
        }

        std::cout << '\n';
    }

    return 0;
}