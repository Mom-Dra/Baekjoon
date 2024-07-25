#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::stack<int> st;
    int sum{ 0 };
    int k;
    
    std::cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int num;
        std::cin >> num;

        if (num == 0)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }


    while (!st.empty())
    {
        int num = st.top();
        st.pop();
        sum += num;
    }

    std::cout << sum;
    
    return 0;
}