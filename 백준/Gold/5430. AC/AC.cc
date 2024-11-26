#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <sstream>

std::vector<int> Split(const std::string& arrStr, char delimeter)
{
    std::vector<int> arr;

    std::string tmp{ arrStr.substr(1, arrStr.size() - 2) };

    std::string token;
    std::istringstream tokenStream(tmp);

    while (std::getline(tokenStream, token, delimeter))
    {
        arr.emplace_back(std::stoi(token));
    }

    return arr;
}

void PrintArr(const std::vector<int>& arr)
{
    for (const auto& num : arr)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /*
    // R(뒤집기) -> 순서 뒤집기
    // D(버리기) -> 첫 번째 수를 버리는 함수
    // 비어 있는데 D를 사용하면 에러가 발생
    */

    int T;
    std::cin >> T;

    for (int i{ 0 }; i < T; ++i)
    {
        std::string p;
        int n;
        std::string arrStr;
        std::vector<int> arr;

        std::cin >> p;
        std::cin >> n;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, arrStr);


        if (n != 0)
        {
            arr = Split(arrStr, ',');
        }

       

        bool isError{ false };
        bool isReverse{ false };

        for (const auto& c : p)
        {
            switch (c)
            {
            case 'R':
                isReverse = !isReverse;
                break;
            case 'D':
                if (arr.empty())
                {
                    isError = true;
                }
                else
                {
                    if (isReverse)
                        arr.pop_back();
                    else
                        arr.erase(arr.begin());
                }
                break;
            }

            if (isError) break;
        }

        if (isError) std::cout << "error\n";
        else
        {
            std::cout << '[';

            if (!arr.empty())
            {
                if (isReverse) std::reverse(arr.begin(), arr.end());

                for (std::size_t i{ 0 }; i < arr.size() - 1; ++i)
                {
                    std::cout << arr[i] << ',';
                }

                std::cout << *(arr.end() - 1);
            }
            std::cout << "]\n";
        }
    }


    return 0;
}
