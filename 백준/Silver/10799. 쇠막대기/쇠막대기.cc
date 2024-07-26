#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> arr;
    std::string s;

    int sum{ 0 };

    std::cin >> s;

    for (int i = 0; i < s.length(); ++i)
    {
        if (i + 1 < s.length() && s[i] == '(' && s[i + 1] == ')')
        {
            for (int j = 0; j < arr.size(); ++j)
            {
                ++arr[j];
            }

            ++i;
        }
        else if(s[i] == '(')
        {
            arr.push_back(1);
        }
        else
        {
            sum += arr.back();
            arr.pop_back();
        }
    }

    std::cout << sum;

    return 0;
}