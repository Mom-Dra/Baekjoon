#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::stack<char> st;

    bool isValid = { true };
    std::string s;
    std::cin >> s;

    int layer{ 0 };
    std::vector<int> arr;

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];

        if (c == '(' || c == '[')
        {
            st.push(c);

            ++layer;
            arr.push_back(0);
        }
        else if (c == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                
                char d = s[i - 1];

                if (d == '(')
                {
                    arr[layer - 1] += 2;
                }
                else if (d == ')' || d == ']')
                {
                    arr[layer - 1] += arr[layer] * 2;
                    arr[layer] = 0;
                }

                --layer;
            }
            else
            {
                isValid = false;
                break;
            }
        }
        else if (c == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();

                char d = s[i - 1];

                if (d == '[')
                {
                    arr[layer - 1] += 3;
                }
                else if (d == ')' || d == ']')
                {
                    arr[layer - 1] += arr[layer] * 3;
                    arr[layer] = 0;
                }

                --layer;
            }
            else
            {
                isValid = false;
                break;
            }
        }
    }

    if (!isValid)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << arr[0];
    }


    return 0;
}