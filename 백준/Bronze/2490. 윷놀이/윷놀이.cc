#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    for (int T = 0; T < 3; ++T)
    {
        int oneCount{ 0 };
        char c;

        for (int i = 0; i < 4; ++i)
        {
            int tmp;
            std::cin >> tmp;
            
            if (tmp) ++oneCount;
        }

        switch (oneCount)
        {
        case 0:
            c = 'D';
            break;
        case 1:
            c = 'C';
            break;
        case 2:
            c = 'B';
            break;
        case 3:
            c = 'A';
            break;
        case 4:
            c = 'E';
            break;
        }

        std::cout << c << '\n';
    }
    

    return 0;
}