#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<bool> arr(7);

    int count{ 0 };
    int price{ 0 };
    int sameVal{ 0 };
    int maxVal{ 0 };

    for (int i = 0; i < 3; ++i)
    {
        int n;
        std::cin >> n;

        if (arr[n])
        {
            ++count;
            sameVal = n;
        }
            
        arr[n] = true;
        maxVal = n > maxVal ? n : maxVal;
    }

    if (count == 2)
    {
        price = 10000 + sameVal * 1000;
    }
    else if (count == 1)
    {
        price = 1000 + (sameVal) * 100;
    }
    else
    {
        price = maxVal * 100;
    }

    std::cout << price;

    return 0;
}